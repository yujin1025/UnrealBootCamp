#include "ExplosionEvent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "SpartaPlayerController.h"

AExplosionEvent::AExplosionEvent()
{
	PrimaryActorTick.bCanEverTick = false;

    ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
    ExplosionCollision->SetSphereRadius(ExplosionRadius);
    SetRootComponent(ExplosionCollision);

    ExplosionInterval = 4.0f;  
    ExplosionDamage = 10.0f;  
    ExplosionRadius = 200.0f; 
    WarningTime = 2.0f;
}

void AExplosionEvent::BeginPlay()
{
	Super::BeginPlay();
	
    PrepareExplosion();

    GetWorld()->GetTimerManager().SetTimer(
        ExplosionTimerHandle,
        this,
        &AExplosionEvent::PrepareExplosion,
        ExplosionInterval,
        true
    );
}

void AExplosionEvent::PrepareExplosion()
{
    ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (PlayerController)
    {
        PlayerController->UpdateWarningUI(true);
    }

    AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Player) return;

    FVector PlayerLocation = Player->GetActorLocation();
    FVector2D RandomOffset = FMath::RandPointInCircle(400.0f); 
    ExplosionLocation = PlayerLocation + FVector(RandomOffset.X, RandomOffset.Y, 0.0f);

    if (WarningEffect)
    {
        WarningParticle = UGameplayStatics::SpawnEmitterAtLocation(
            GetWorld(),
            WarningEffect,
            ExplosionLocation
        );
    }

    GetWorld()->GetTimerManager().SetTimer(
        WarningTimerHandle,
        this,
        &AExplosionEvent::TriggerExplosion,
        WarningTime,
        false
    );
}

void AExplosionEvent::TriggerExplosion()
{
    ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    if (PlayerController)
    {
        PlayerController->UpdateWarningUI(false);
    }

    if (WarningParticle)
    {
        WarningParticle->DestroyComponent();
    }

    if (ExplosionEffect)
    {
        Particle = UGameplayStatics::SpawnEmitterAtLocation(
            GetWorld(),
            ExplosionEffect,
            ExplosionLocation
        );
    }

    AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (Player && FVector::Dist(Player->GetActorLocation(), ExplosionLocation) <= ExplosionRadius)
    {
        UGameplayStatics::ApplyDamage(
            Player,
            ExplosionDamage,
            nullptr,
            this,
            UDamageType::StaticClass()
        );
    }

    GetWorld()->GetTimerManager().SetTimer(
        DestroyParticleTimerHandle,
        this,
        &AExplosionEvent::DestroyExplosion,
        0.5f,
        false
    );
}

void AExplosionEvent::DestroyExplosion()
{
    if (Particle)
    {
        Particle->DestroyComponent();
    }
}


