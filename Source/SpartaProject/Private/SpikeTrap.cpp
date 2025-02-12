#include "SpikeTrap.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ASpikeTrap::ASpikeTrap()
{
	PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrapMesh"));
    SetRootComponent(StaticMesh);

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

    SpikeInterval = 2.0f;
    Damage = 20.0f;
    bSpikeActive = false;
}

void ASpikeTrap::BeginPlay()
{
	Super::BeginPlay();
	
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASpikeTrap::OnTriggerEnter);

    GetWorld()->GetTimerManager().SetTimer(
        SpikeTimerHandle,
        this,
        &ASpikeTrap::Spike,
        SpikeInterval,
        true
    );
}

void ASpikeTrap::Spike()
{
    
    if (bSpikeActive)
    {
        StaticMesh->SetHiddenInGame(true);
        TriggerBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

        bSpikeActive = false;
    }
    else
    {
        StaticMesh->SetHiddenInGame(false);
        TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

        bSpikeActive = true;
    }
}

void ASpikeTrap::OnTriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        UGameplayStatics::ApplyDamage(
            OtherActor,
            Damage, 
            nullptr, 
            this, 
            UDamageType::StaticClass());
    }
}
