#include "SlowingItem.h"
#include "SpartaCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SpartaPlayerController.h"

ASlowingItem::ASlowingItem()
{
	SlowAmount = 0.5f; 
	SlowDuration = 5.0f;
}

void ASlowingItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (ASpartaCharacter* Character = Cast<ASpartaCharacter>(Activator))
	{
		if (Character)
		{
			UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
			if (MovementComponent)
			{
				OriginalSpeed = MovementComponent->MaxWalkSpeed;
				MovementComponent->MaxWalkSpeed *= SlowAmount;

				GetWorld()->GetTimerManager().SetTimer(
					SlowingTimerHandle,
					[this, Activator]() {
						RestoreSpeed(Activator); 
					},
					SlowDuration,
					false
				);

				if (APlayerController* PC = Cast<APlayerController>(Character->GetController()))
				{
					if (ASpartaPlayerController* SpartaPC = Cast<ASpartaPlayerController>(PC))
					{
						SpartaPC->UpdateSlowUI(true); 
					}
				}
			}
		}
	}
}

void ASlowingItem::RestoreSpeed(AActor* Activator)
{
	if (ASpartaCharacter* Character = Cast<ASpartaCharacter>(Activator))
	{
		UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
		if (MovementComponent)
		{
			MovementComponent->MaxWalkSpeed = OriginalSpeed;
		}

		if (APlayerController* PC = Cast<APlayerController>(Character->GetController()))
		{
			if (ASpartaPlayerController* SpartaPC = Cast<ASpartaPlayerController>(PC))
			{
				SpartaPC->UpdateSlowUI(false);
			}
		}
	}
}
