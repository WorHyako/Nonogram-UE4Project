#include "GridManager.h"

#include "Kismet/GameplayStatics.h"

AGridManager::AGridManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGridManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Owner = this;
	_textureReader = GetWorld()->SpawnActor<ATextureReader>(spawnParameters);
	// FString("/Game/Images/T_Panda.T_Panda")
	_textureReader->LoadTexture(FString("/Game/Images/T_Panda.T_Panda"));
	_gridInner = GetWorld()->SpawnActor<AGridInner>(spawnParameters);
	_gridOuter = GetWorld()->SpawnActor<AGridOuter>(spawnParameters);
	ScanTexture();
	if (_rowCount > 0 && _columnCount > 0) BuildAllGrids();
}

void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGridManager::BuildAllGrids()
{
	TArray<AGridBase*> grids;
	grids.Add(_gridInner);
	grids.Add(_gridOuter);
	for (auto each : grids)
	{
		each->_gridRowCount = _rowCount;
		each->_gridColumnCount = _columnCount;
	}
	_gridInner->RefreshGrid();
	_gridOuter->RefreshGrid(_textureReader->_whiteIndexMatrix);
	_gridInner->BrushGridWithBool(_textureReader->_whiteIndexMatrix);

	FVector cameraLocation;
	cameraLocation.X = _columnCount * _cellScale / 2;
	cameraLocation.Y = _rowCount * _cellScale / 2;
	cameraLocation.Z = _rowCount > _columnCount
		                   ? _rowCount * _cellScale / 2 * 1.4f
		                   : _columnCount * _cellScale / 2 * 1.4f;
	TArray<AActor*> foundedActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "MainCamera", foundedActors);
	if (foundedActors.Num() > 0)
		foundedActors[0]->SetActorLocation(cameraLocation);
}

void AGridManager::ScanTexture()
{
	_textureReader->ScanTexture();
	_rowCount = _textureReader->_textureSizeY;
	_columnCount = _textureReader->_textureSizeX;
}
