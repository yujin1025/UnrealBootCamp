#include "MyActor.h"


AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	curPos = FVector2D(0, 0);
	totDist = 0.0f;
	evCnt = 0;
	stepCnt = 0;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 10; ++i)
	{
		Move();
	}

	UE_LOG(LogTemp, Log, TEXT("Total Distance: %.2f"), totDist);
	UE_LOG(LogTemp, Log, TEXT("Total Events: %d"), evCnt);
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// (0,0)���� 10ȸ �����̸鼭 ��ǥ�� ���
void AMyActor::Move()
{
	stepCnt++;
	FVector2D prePos = curPos;
	int stepX = Step();
	int stepY = Step();

	curPos.X += stepX;
	curPos.Y += stepY;
	float distance = Distance(prePos, curPos);
	totDist += distance;

	UE_LOG(LogTemp, Log, TEXT("Step %d: (%.0f, %.0f)"), stepCnt, curPos.X, curPos.Y);
	UE_LOG(LogTemp, Log, TEXT("Moved distance: %.2f"), distance);
	
	if (CreateEvent())
	{
		evCnt++;
		UE_LOG(LogTemp, Log, TEXT("Event trigger!"));
	}
}

// x��ǥ y��ǥ ���� �̵��� �Ÿ�
int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

// ���� ��ǥ���� �̵� �Ÿ�
float AMyActor::Distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

// 50% Ȯ���� �����ϰ� �̺�Ʈ�� �߻�
int32 AMyActor::CreateEvent()
{
	return FMath::RandRange(0, 1);
}

