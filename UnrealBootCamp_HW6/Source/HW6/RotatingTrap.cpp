#include "RotatingTrap.h"

ARotatingTrap::ARotatingTrap()
{
 	PrimaryActorTick.bCanEverTick = true;

	RotatingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingMesh"));
    RootComponent = RotatingMesh;
}

void ARotatingTrap::BeginPlay()
{
	Super::BeginPlay();

    OriginalRotation = RotatingMesh->GetRelativeRotation();
    GetWorld()->GetTimerManager().SetTimer(RotationTimerHandle, this, &ARotatingTrap::ToggleRotation, RotationInterval, true);
}

void ARotatingTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bIsRotating)
    {
        //Yaw축 기준으로 회전
        FRotator NewRotation = FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f);
        RotatingMesh->AddLocalRotation(NewRotation);
    }
    else
    {
        RotatingMesh->SetRelativeRotation(OriginalRotation);
    }
}

void ARotatingTrap::ToggleRotation()
{
    bIsRotating = !bIsRotating;
}