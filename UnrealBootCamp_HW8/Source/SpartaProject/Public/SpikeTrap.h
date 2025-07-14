#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpikeTrap.generated.h"

class UBoxComponent;

UCLASS()
class SPARTAPROJECT_API ASpikeTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpikeTrap();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trap")
    UStaticMeshComponent* StaticMesh;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trap")
    UBoxComponent* TriggerBox;

    virtual void BeginPlay() override;

    void Spike();

    UFUNCTION()
    void OnTriggerEnter(
        UPrimitiveComponent* OverlappedComp, 
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp, 
        int32 OtherBodyIndex,
        bool bFromSweep, 
        const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trap")
    float SpikeInterval; 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trap")
    float Damage;
    bool bSpikeActive;

    FTimerHandle SpikeTimerHandle;

};
