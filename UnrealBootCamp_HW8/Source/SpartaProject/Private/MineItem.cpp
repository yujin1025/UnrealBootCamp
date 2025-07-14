#include "MineItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.0f;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30.0f;
	ItemType = "Mine";
    bHasExploded = false;

    ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
    ExplosionCollision->InitSphereRadius(ExplosionRadius);
    ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    ExplosionCollision->SetupAttachment(Scene);
}

void AMineItem::ActivateItem(AActor* Activator)
{
    if (bHasExploded) return;

    Super::ActivateItem(Activator);

    GetWorld()->GetTimerManager().SetTimer(
        ExplosionTimerHandle, 
        this, 
        &AMineItem::Explode, 
        ExplosionDelay,
        false
    );

    bHasExploded = true;
}

void AMineItem::Explode()
{
    TWeakObjectPtr<UParticleSystemComponent> WeakParticle = nullptr;

    if (ExplosionParticle)
    {
        UParticleSystemComponent* Particle = UGameplayStatics::SpawnEmitterAtLocation(
            GetWorld(),
            ExplosionParticle,
            GetActorLocation(),
            GetActorRotation(),
            false
        );
        WeakParticle = Particle;
    }

    if (ExplosionSound)
    {
        UGameplayStatics::PlaySoundAtLocation(
            GetWorld(),
            ExplosionSound,
            GetActorLocation()
        );
    }

    TArray<AActor*> OverlappingActors;
    ExplosionCollision->GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor && Actor->ActorHasTag("Player"))
        {
            UGameplayStatics::ApplyDamage(
                Actor,                    
                ExplosionDamage,         
                nullptr,                   
                this,                       
                UDamageType::StaticClass()  
            );
        }
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

    DestroyItem();
}
