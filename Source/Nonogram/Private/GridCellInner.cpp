#include "GridCellInner.h"

AGridCellInner::AGridCellInner()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> FoundedMaterial(TEXT("/Game/Materials/MI_Black.MI_Black"));
	if(FoundedMaterial.Succeeded())
		_planeComponent->SetMaterial(0, FoundedMaterial.Object);
}
