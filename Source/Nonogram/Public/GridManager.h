#pragma once

#include "CoreMinimal.h"
#include "GridInner.h"
#include "GridOuter.h"
#include "TextureReader.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

UCLASS()
class NONOGRAM_API AGridManager
	: public AActor
{
	GENERATED_BODY()

public:
	AGridManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _rowCount = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _columnCount = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _cellScale = 100;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	ATextureReader* _textureReader = nullptr;
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	AGridInner* _gridInner = nullptr;
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	AGridOuter* _gridOuter = nullptr;

	UFUNCTION(BlueprintCallable)
	void BuildAllGrids();

	UFUNCTION(BlueprintCallable)
	void ScanTexture();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
