#include "BlinkingPlatform.h"

ABlinkingPlatform::ABlinkingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	BlinkingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = BlinkingMesh;
}

void ABlinkingPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetVisibility();
	GetWorld()->GetTimerManager().SetTimer(BlinkTimerHandle, this, &ABlinkingPlatform::ToggleVisibility, BlinkInterval, true);
}

void ABlinkingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlinkingPlatform::ToggleVisibility()
{
	bIsVisible = !bIsVisible;
	SetVisibility();
}

void ABlinkingPlatform::SetVisibility()
{
	BlinkingMesh->SetVisibility(bIsVisible);
	BlinkingMesh->SetCollisionEnabled(bIsVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}

