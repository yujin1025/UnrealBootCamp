#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class HW6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MovingMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float MoveSpeed = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float MaxRange = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float RandomRange = 200.0f;

private:
	FVector StartLocation;
	bool bMovingForward = true;
};
