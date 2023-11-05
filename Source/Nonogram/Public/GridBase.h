#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridCellBase.h"
#include "GridBase.generated.h"

UCLASS()
class NONOGRAM_API AGridBase
	: public AActor
{
	GENERATED_BODY()

public:
	AGridBase();

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* _defaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AGridCellBase*> _cellObjectArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGridCellBase> _cellClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true))
	TArray<FVector> _cellLocationArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int _gridRowCount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int _gridColumnCount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int _gridCellScale = 100;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void RefreshGrid();
	
	virtual void RefreshGrid(bool** whiteIndexes_);

	UFUNCTION(BlueprintCallable)
	virtual void SpawnCellOnVector(AGridCellBase* pointClass_, TArray<FVector> vectorPoint_);

	virtual void CalculateCellVector(int rowCount_, int columnCount_, int cellScale_, bool** whiteIndexes_ = nullptr);

	void BrushGridWithBool(bool** whiteIndexes_);
};
