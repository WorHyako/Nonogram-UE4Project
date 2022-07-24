#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridBase.generated.h"

UCLASS()
class NONOGRAM_API AGridBase
	: public AActor
{
	GENERATED_BODY()

public:
	AGridBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
