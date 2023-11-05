#pragma once

#include "CoreMinimal.h"
#include "GridBase.h"
#include "GridInner.generated.h"

UCLASS()
class NONOGRAM_API AGridInner
	: public AGridBase
{
	GENERATED_BODY()
public:
	AGridInner();

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeComponent;

	virtual void BeginPlay() override;

	virtual void RefreshGrid() override;

	virtual void CalculateCellVector(int const rowCount_, int const columnCount_, int const pointScale_,
	                                             bool** whiteIndexes_ = nullptr) override;
};
