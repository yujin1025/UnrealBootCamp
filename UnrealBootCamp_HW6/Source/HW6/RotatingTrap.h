#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingTrap.generated.h"

UCLASS()
class HW6_API ARotatingTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingTrap();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RotatingMesh;

	// 회전 속도 및 주기
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float RotationSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Setting")
	float RotationInterval = 3.0f;

private:
	void ToggleRotation();

	FTimerHandle RotationTimerHandle;
	FRotator OriginalRotation;
	bool bIsRotating = false;
};
