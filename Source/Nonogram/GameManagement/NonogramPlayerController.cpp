#include "NonogramPlayerController.h"

#include "NonogramPlayerCameraManager.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

ANonogramPlayerController::ANonogramPlayerController()
{
	bEnableClickEvents = true;
	bShowMouseCursor = true;
	PlayerCameraManagerClass = ANonogramPlayerCameraManager::StaticClass();
}

void ANonogramPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> foundedActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "MainCamera", foundedActors);
	if (foundedActors.Num() > 0)
	{
		ACameraActor* camera = Cast<ACameraActor>(foundedActors[0]);
		if (camera) PlayerCameraManager->SetViewTarget(camera);
	}
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ANonogramPlayerController::LeftMouseClicked);
}

void ANonogramPlayerController::LeftMouseClicked()
{
}
