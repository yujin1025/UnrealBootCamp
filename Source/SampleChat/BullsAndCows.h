#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BullsAndCows.generated.h"

UCLASS()
class UBullsAndCows : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "BullsAndCows")
    static FString GenerateRandomNumber();
    
    UFUNCTION(BlueprintCallable, Category = "BullsAndCows")
    static FString CheckBullsAndCows(const FString& ServerNumber, const FString& PlayerNumber);

    UFUNCTION(BlueprintCallable, Category = "BullsAndCows")
    static bool ValidatePlayerNumber(const FString& PlayerNumber);
};