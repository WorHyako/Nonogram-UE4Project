#include "GridBase.h"

AGridBase::AGridBase()
{
	PrimaryActorTick.bCanEverTick = true;

	_defaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _defaultSceneRoot;
}

void AGridBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGridBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGridBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	_cellObjectArray.Reset();
	_cellLocationArray.Reset();

	Super::EndPlay(EndPlayReason);
}

void AGridBase::RefreshGrid()
{
	for (auto each : _cellObjectArray)
		if (each != nullptr)
		{
			each->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
			each->Destroy();
		}
}

void AGridBase::RefreshGrid(bool** whiteIndexes_)
{
}

void AGridBase::SpawnCellOnVector(AGridCellBase* pointClass_, TArray<FVector> vectorPoint_)
{
	int num = vectorPoint_.Num();
	for (int i = 0; i < num; i++)
	{
		FActorSpawnParameters spawnParameters;
		spawnParameters.Owner = this;
		const FRotator* spawnRotator = new FRotator(0.f, 0.f, 0.f);
		const FVector spawnLocation = vectorPoint_[i];
		AGridCellBase* spawnedActor = GetWorld()->SpawnActor<AGridCellBase>(pointClass_->GetClass(), spawnLocation,
		                                                                    *spawnRotator, spawnParameters);
		if (spawnedActor != nullptr)
		{
			spawnedActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			_cellObjectArray.Add(spawnedActor);
		}
	}
}

void AGridBase::CalculateCellVector(int rowCount_, int columnCount_, int cellScale_, bool** whiteIndexes_)
{
}

// void AGridBase::BrushGrid(TArray<int> indexes_)
// {
// 	auto FoundedMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Materials/MI_White.MI_White"));
// 	if (!FoundedMaterial) return;
// 	for (auto const each : indexes_)
// 		_pointObject[each]->_planeComponent->SetMaterial(0, FoundedMaterial);
// }

void AGridBase::BrushGridWithBool(bool** whiteIndexes_)
{
	auto FoundedMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Materials/MI_White.MI_White"));
	if (!FoundedMaterial) return;
	for (int i = 0; i < _gridRowCount; i++)
		for (int j = 0; j < _gridColumnCount; j++)
			if (whiteIndexes_[i][j])
				_cellObjectArray[i * _gridColumnCount + j]->_planeComponent->SetMaterial(0, FoundedMaterial);
}
