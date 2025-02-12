#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosionEvent.generated.h"

class USphereComponent;

UCLASS()
class SPARTAPROJECT_API AExplosionEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	AExplosionEvent();

protected:
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    USphereComponent* ExplosionCollision;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    UParticleSystem* WarningEffect;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    UParticleSystem* ExplosionEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    float ExplosionDamage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    float ExplosionRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    float ExplosionInterval;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion")
    float WarningTime;

    FTimerHandle ExplosionTimerHandle;
    FTimerHandle WarningTimerHandle;
    FTimerHandle DestroyParticleTimerHandle;

    UParticleSystemComponent* WarningParticle;
    UParticleSystemComponent* Particle;
    FVector ExplosionLocation;

    void PrepareExplosion();
    void TriggerExplosion();
    void DestroyExplosion();
};
