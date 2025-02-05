#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

struct FInputActionValue;

UCLASS()
class HW7_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float AirMoveMultiplier = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed = 1.0f;

	bool bHasTouchedGround = false;
	bool IsGround() const;
	FVector Velocity = FVector::ZeroVector;
};
