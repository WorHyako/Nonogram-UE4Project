#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "GridCellBase.generated.h"

UCLASS()
class NONOGRAM_API AGridCellBase
	: public AActor
{
	GENERATED_BODY()

public:
	AGridCellBase();

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	USceneComponent* _defaultSceneRoot;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* _planeComponent;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
