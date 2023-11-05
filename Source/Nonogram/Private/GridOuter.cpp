#include "GridOuter.h"
#include "GridCellOuter.h"

AGridOuter::AGridOuter()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundedMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundedMaterial(
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if (FoundedMesh.Succeeded() && FoundedMaterial.Succeeded())
	{
		_planeUpComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneUp"));
		_planeUpComponent->SetStaticMesh(FoundedMesh.Object);
		_planeUpComponent->SetMaterial(0, FoundedMaterial.Object);
		_planeUpComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

		_planeDownComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneDown"));
		_planeDownComponent->SetStaticMesh(FoundedMesh.Object);
		_planeDownComponent->SetMaterial(0, FoundedMaterial.Object);
		_planeDownComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

		_planeLeftComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneLeft"));
		_planeLeftComponent->SetStaticMesh(FoundedMesh.Object);
		_planeLeftComponent->SetMaterial(0, FoundedMaterial.Object);
		_planeLeftComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

		_planeRightComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneRight"));
		_planeRightComponent->SetStaticMesh(FoundedMesh.Object);
		_planeRightComponent->SetMaterial(0, FoundedMaterial.Object);
		_planeRightComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}
	_cellClass = AGridCellOuter::StaticClass();
}

void AGridOuter::BeginPlay()
{
	Super::BeginPlay();
}

void AGridOuter::RefreshGrid(bool** whiteIndexes_)
{
	Super::RefreshGrid();

	CalculateCellVector(_gridRowCount, _gridColumnCount, _gridCellScale, whiteIndexes_);
	SpawnCellOnVector(_cellClass.GetDefaultObject(), _cellLocationArray);

	TArray<UStaticMeshComponent*> planeArr;
	UStaticMeshComponent* upDownPlanes[] = {_planeUpComponent, _planeDownComponent};
	planeArr.Append(upDownPlanes, UE_ARRAY_COUNT(upDownPlanes));

	FTransform newTransform;
	for (int16 step = 0; step < 2; step++)
	{
		newTransform.SetScale3D(FVector(_gridColumnCount * _gridCellScale, _gridCellScale, 100.f) / 100.f);
		if (step == 0)
		{
			newTransform.SetLocation(FVector(_gridColumnCount * _gridCellScale / 2 - _gridCellScale / 2,
			                                 _gridCellScale * -1, 0.f));
			planeArr[step]->SetRelativeTransform(newTransform);
		}
		else
		{
			newTransform.SetLocation(FVector(_gridColumnCount * _gridCellScale / 2 - _gridCellScale / 2,
			                                 _gridCellScale * _gridRowCount, 0.f));
			planeArr[step]->SetRelativeTransform(newTransform);
		}
	}

	planeArr.Reset();
	UStaticMeshComponent* leftRightPlanes[] = {_planeLeftComponent, _planeRightComponent};
	planeArr.Append(leftRightPlanes, UE_ARRAY_COUNT(leftRightPlanes));
	for (int16 step = 0; step < 2; step++)
	{
		newTransform.SetScale3D(FVector(_gridCellScale, _gridRowCount * _gridCellScale, 100.f) / 100.f);
		if (step == 0)
		{
			newTransform.SetLocation(FVector(_gridColumnCount * _gridCellScale,
			                                 _gridRowCount * _gridCellScale / 2 - _gridCellScale / 2, 0.f));
			planeArr[step]->SetRelativeTransform(newTransform);
		}
		else
		{
			newTransform.SetLocation(FVector(_gridCellScale * -1,
			                                 _gridRowCount * _gridCellScale / 2 - _gridCellScale / 2, 0.f));
			planeArr[step]->SetRelativeTransform(newTransform);
		}
	}
}

void AGridOuter::CalculateCellVector(int const rowCount_, int const columnCount_, int const cellScale_,
                                     bool** whiteIndexes_)
{
	//Super::CalculatePointVector(rowCount_, columnCount_, pointScale_, rowThickness_, columnThickness_);

	if (!whiteIndexes_) return;
	// Black lines in rows
	for (int i = 0; i < rowCount_; i++)
	{
		_gridRowThickness.Insert(0, i);
		bool oneLine = false;
		for (int j = 0; j < columnCount_; j++)
			if (whiteIndexes_[i][j])
				oneLine = false;
			else
			{
				if (oneLine) continue;
				oneLine = true;
				_gridRowThickness[i]++;
			}
	}
	// Black lines in columns
	for (int j = 0; j < columnCount_; j++)
	{
		_gridColumnThickness.Insert(0, j);
		bool oneLine = false;
		for (int i = 0; i < rowCount_; i++)
			if (whiteIndexes_[j][i])
				oneLine = false;
			else
			{
				if (oneLine) continue;
				oneLine = true;
				_gridColumnThickness[j]++;
			}
	}

	// Left side
	for (int row = 0; row < rowCount_; row++)
		if (_gridRowThickness[row])
			for (int thickness = 0; thickness < _gridRowThickness[row]; thickness++)
				_cellLocationArray.Add(FVector(cellScale_ * thickness * -1 - cellScale_, row * cellScale_, 0.f));
		else _cellLocationArray.Add(FVector(cellScale_ * -1, row * cellScale_, 0.f));
	// Up side
	for (int column = 0; column < columnCount_; column++)
		if (_gridColumnThickness[column])
			for (int thickness = 0; thickness < _gridColumnThickness[column]; thickness++)
				_cellLocationArray.Add(FVector(column * cellScale_, cellScale_ * thickness * -1 - cellScale_, 0.f));
		else
			_cellLocationArray.Add(FVector(column * cellScale_, cellScale_ * -1, 0.f));
	// Right side 
	for (int row = 0; row < rowCount_; row++)
		_cellLocationArray.Add(FVector(columnCount_ * cellScale_, row * cellScale_, 0.f));
	// Down side
	for (int column = 0; column < columnCount_; column++)
		_cellLocationArray.Add(FVector(column * cellScale_, cellScale_ * rowCount_, 0.f));
}

void AGridOuter::SetCellNumbers()
{
}
