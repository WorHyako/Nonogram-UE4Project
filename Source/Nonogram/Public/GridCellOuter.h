#pragma once

#include "CoreMinimal.h"
#include "GridCellBase.h"
#include "GridCellOuter.generated.h"

UCLASS()
class NONOGRAM_API AGridCellOuter
	: public AGridCellBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UTextRenderComponent* _textRenderComponent;
	
	AGridCellOuter();

protected:
	virtual void BeginPlay() override;
};
