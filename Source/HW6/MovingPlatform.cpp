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

    //����ġ���� x,y�� �������� ���� �������� �����ϰ� ����
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

