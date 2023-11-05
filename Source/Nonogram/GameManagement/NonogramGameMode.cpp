#include "NonogramGameMode.h"
#include "NonogramPlayerController.h"

ANonogramGameMode::ANonogramGameMode()
{
	PlayerControllerClass = ANonogramPlayerController::StaticClass();
	DefaultPawnClass = nullptr;
}
