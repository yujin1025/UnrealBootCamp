#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class STUDY1_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void Move();
	int32 Step();
	float Distance(FVector2D first, FVector2D second);
	int32 CreateEvent();

private:
	FVector2D curPos;
	float totDist;
	int32 evCnt;
	int32 stepCnt;
};
