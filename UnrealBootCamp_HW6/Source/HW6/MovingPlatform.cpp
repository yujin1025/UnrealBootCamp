#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

    MovingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingMesh"));
    RootComponent = MovingMesh;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

    //현위치에서 x,y축 기준으로 일정 범위내로 랜덤하게 스폰
    StartLocation = GetActorLocation();
    FVector RandomLocation = StartLocation + FVector(
        FMath::RandRange(-RandomRange, RandomRange),
        FMath::RandRange(-RandomRange, RandomRange),
        0.0f                                
    );

    SetActorLocation(RandomLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();
    float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

    if (DistanceMoved >= MaxRange)
    {
        bMovingForward = !bMovingForward;
    }

    float Direction = bMovingForward ? 1.0f : -1.0f;
    AddActorLocalOffset(FVector(Direction * MoveSpeed * DeltaTime, 0, 0));
}

