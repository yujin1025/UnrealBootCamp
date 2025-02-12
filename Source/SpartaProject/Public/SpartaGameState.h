#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"

UCLASS()
class SPARTAPROJECT_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()
	
public:
    ASpartaGameState();

    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Score;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 SpawnedCoinCount;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 CollectedCoinCount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
    float WaveDuration;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 CurrentLevelIndex;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 MaxLevels;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
    TArray<FName> LevelMapNames;
    int32 WaveIndex;
    int32 MaxWaves;

    FTimerHandle WaveTimerHandle;
    FTimerHandle HUDUpdateTimerHandle;

    UPROPERTY(EditAnywhere, Category = "Trap")
    TSubclassOf<AActor> SpikeTrapClass;
    UPROPERTY(EditAnywhere, Category = "Explosion")
    TSubclassOf<AActor> ExplosionEventClass;

    UFUNCTION(BlueprintPure, Category = "Score")
    int32 GetScore() const;
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);
    UFUNCTION(BlueprintCallable, Category = "Level")
    void OnGameOver();

    void StartLevel(); 
    void StartWave();
    void OnLevelTimeUp();
    void OnWaveTimeUp();
    void OnCoinCollected();
    void EndLevel();
    void UpdateHUD();
    void TriggerWaveEvent(int32 Wave);
};
