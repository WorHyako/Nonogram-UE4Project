#include "Nonogram/Public/GridManager.h"

AGridManager::AGridManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGridManager::BeginPlay()
{
	Super::BeginPlay();
}

void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
