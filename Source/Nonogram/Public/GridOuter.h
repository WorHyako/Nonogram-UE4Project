#pragma once

#include "CoreMinimal.h"
#include "GridBase.h"
#include "GridOuter.generated.h"

UCLASS()
class NONOGRAM_API AGridOuter
	: public AGridBase
{
	GENERATED_BODY()
public:
	AGridOuter();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeUpComponent;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeDownComponent;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeLeftComponent;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeRightComponent;

	UPROPERTY(BlueprintReadOnly)
	TArray<int> _gridRowThickness;

	UPROPERTY(BlueprintReadOnly)
	TArray<int> _gridColumnThickness;

	virtual void RefreshGrid(bool** whiteIndexes_) override;

	virtual void CalculateCellVector(int const rowCount_, int const columnCount_, int const cellScale_,
	                                             bool** whiteIndexes_=nullptr) override;

	void SetCellNumbers();
};
