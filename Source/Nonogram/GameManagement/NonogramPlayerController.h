#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NonogramPlayerController.generated.h"

UCLASS()
class NONOGRAM_API ANonogramPlayerController
	: public APlayerController
{
	GENERATED_BODY()

public:
	ANonogramPlayerController();

protected:
	virtual void BeginPlay() override;

	void LeftMouseClicked();
};
