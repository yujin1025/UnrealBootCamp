#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SlowingItem.generated.h"

UCLASS()
class SPARTAPROJECT_API ASlowingItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	ASlowingItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slowing")
	float SlowAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slowing")
	float SlowDuration;
	float OriginalSpeed;

	FTimerHandle SlowingTimerHandle;

	virtual void ActivateItem(AActor* Activator) override;
	void RestoreSpeed(AActor* Activator);
};
