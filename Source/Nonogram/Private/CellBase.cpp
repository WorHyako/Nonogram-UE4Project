#include "Nonogram/Public/CellBase.h"

ACellBase::ACellBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACellBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACellBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
