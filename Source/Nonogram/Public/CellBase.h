#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellBase.generated.h"

UCLASS()
class NONOGRAM_API ACellBase
	: public AActor
{
	GENERATED_BODY()

public:
	ACellBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
