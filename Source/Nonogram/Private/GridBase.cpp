#include "Nonogram/Public/GridBase.h"

AGridBase::AGridBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGridBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGridBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
