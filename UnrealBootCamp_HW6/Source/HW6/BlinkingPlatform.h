#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkingPlatform.generated.h"

UCLASS()
class HW6_API ABlinkingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlinkingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BlinkingMesh;

	UPROPERTY(EditAnywhere, Category = "Platform Setting")
	float BlinkInterval = 2.0f; 

	UPROPERTY(EditAnywhere, Category = "Platform Setting")
	bool bIsVisible = true;

private:
	void ToggleVisibility();
	void SetVisibility();

	FTimerHandle BlinkTimerHandle;
};
