#include "GridInner.h"
#include "GridCellInner.h"

AGridInner::AGridInner()
{
	_planeComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if(FoundMesh.Succeeded()) _planeComponent->SetStaticMesh(FoundMesh.Object);
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if(FoundMaterial.Succeeded()) _planeComponent->SetMaterial(0, FoundMaterial.Object);
	_planeComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	_cellClass = AGridCellInner::StaticClass();
}

void AGridInner::BeginPlay()
{
	Super::BeginPlay();
}

void AGridInner::RefreshGrid()
{
	Super::RefreshGrid();
	CalculateCellVector(_gridRowCount, _gridColumnCount, _gridCellScale);
	SpawnCellOnVector(_cellClass.GetDefaultObject(), _cellLocationArray);
}

void AGridInner::CalculateCellVector(int const rowCount_, int const columnCount_, int const pointScale_,
												 bool** whiteIndexes_)
{
	// Super::CalculatePointVector(rowCount_, columnCount_, pointScale_, rowThickness_, columnThickness_);
	for (int row = 0; row < rowCount_; row++)
		for (int column = 0; column < columnCount_; column++)
		{
			FVector vectorPoint;
			vectorPoint.X = column * pointScale_;
			vectorPoint.Y = row * pointScale_;
			vectorPoint.Z = 0.f;
			_cellLocationArray.Add(vectorPoint);
		}
	FTransform planeTransform;
	planeTransform.SetLocation(_cellLocationArray[_cellLocationArray.Num() - 1] / 2);
	planeTransform.SetScale3D(FVector(columnCount_ * pointScale_, rowCount_ * pointScale_, 100.f) / 100.f);
	_planeComponent->SetRelativeTransform(planeTransform);
}