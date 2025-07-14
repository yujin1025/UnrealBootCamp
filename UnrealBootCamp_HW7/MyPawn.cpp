#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Capsule);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsGround())
	{
		Velocity.X *= AirMoveMultiplier;
		Velocity.Y *= AirMoveMultiplier;
		Velocity.Z += -980.f * DeltaTime;
		AddActorLocalOffset(Velocity * DeltaTime, true);
		bHasTouchedGround = false;
	}
	else
	{
		FRotator CurrentRotation = GetActorRotation();

		if (!bHasTouchedGround)
		{
			SetActorRotation(FRotator(0.f, CurrentRotation.Yaw, 0.f));
			bHasTouchedGround = true; 
		}
	}
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInput)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPawn::Look);
	}
}

void AMyPawn::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	const FVector MoveInput = Value.Get<FVector>();
	Velocity.Z = MoveInput.Z * MoveSpeed;
	AddActorLocalOffset(MoveInput * MoveSpeed * GetWorld()->GetDeltaSeconds(), true);
}

void AMyPawn::Look(const FInputActionValue& Value)
{
	const FVector LookInput = Value.Get<FVector>();
	FRotator NewRotation = FRotator(LookInput.Y * RotationSpeed, LookInput.X * RotationSpeed, LookInput.Z * RotationSpeed);
	AddActorLocalRotation(NewRotation);
}

bool AMyPawn::IsGround() const
{
	FVector Start = GetActorLocation();
	FVector End = Start + FVector(0.0f, 0.0f, -90.0f);

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);
	return bHit;
}

