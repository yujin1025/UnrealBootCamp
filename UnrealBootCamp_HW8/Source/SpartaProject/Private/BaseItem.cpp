#include "BaseItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    Collision->SetupAttachment(Scene);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Collision);

    Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
    Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);
}

void ABaseItem::OnItemOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!!")));
        ActivateItem(OtherActor);
    }
}

void ABaseItem::OnItemEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
}

void ABaseItem::ActivateItem(AActor* Activator)
{
    TWeakObjectPtr<UParticleSystemComponent> WeakParticle = nullptr;

    if (PickupParticle)
    {
        UParticleSystemComponent* Particle = UGameplayStatics::SpawnEmitterAtLocation(
            GetWorld(),
            PickupParticle,
            GetActorLocation(),
            GetActorRotation(),
            true
        );
        WeakParticle = Particle;
    }

    if (PickupSound)
    {
        UGameplayStatics::PlaySoundAtLocation(
            GetWorld(),      
            PickupSound,
            GetActorLocation()
        );
    }

    FTimerHandle DestroyParticleTimerHandle;

    GetWorld()->GetTimerManager().SetTimer(
        DestroyParticleTimerHandle,
        [WeakParticle]()
        {
            if (WeakParticle.IsValid())
            {
                WeakParticle->DestroyComponent();
            }
        },
        2.0f,
        false
    );
}

FName ABaseItem::GetItemType() const
{
	return ItemType;
}

void ABaseItem::DestroyItem()
{
	Destroy();
}