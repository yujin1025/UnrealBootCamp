#include "ReverseControlItem.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"

AReverseControlItem::AReverseControlItem()
{
	ReverseDuration = 5.0f;
}

void AReverseControlItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (ASpartaCharacter* Character = Cast<ASpartaCharacter>(Activator))
	{
		Character->SetReverseControl(true);

		if (APlayerController* PC = Cast<APlayerController>(Character->GetController()))
		{
			if (ASpartaPlayerController* SpartaPC = Cast<ASpartaPlayerController>(PC))
			{
				SpartaPC->UpdateReverseUI(true);
			}
		}

		GetWorld()->GetTimerManager().SetTimer(
			ReverseControlTimerHandle,
			[this, Activator]() {
				RestoreControl(Activator);
			},
			ReverseDuration,
			false
		);
	}
}

void AReverseControlItem::RestoreControl(AActor* Activator)
{
	if (ASpartaCharacter* Character = Cast<ASpartaCharacter>(Activator))
	{
		Character->SetReverseControl(false);

		if (APlayerController* PC = Cast<APlayerController>(Character->GetController()))
		{
			if (ASpartaPlayerController* SpartaPC = Cast<ASpartaPlayerController>(PC))
			{
				SpartaPC->UpdateReverseUI(false);
			}
		}
	}
}
