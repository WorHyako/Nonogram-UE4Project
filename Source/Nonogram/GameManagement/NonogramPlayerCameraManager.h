#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "NonogramPlayerCameraManager.generated.h"

UCLASS()
class NONOGRAM_API ANonogramPlayerCameraManager
	: public APlayerCameraManager
{
	GENERATED_BODY()

public:
	ANonogramPlayerCameraManager();
};
