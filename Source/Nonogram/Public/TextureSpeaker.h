#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TextureSpeaker.generated.h"

UCLASS()
class NONOGRAM_API ATextureSpeaker
	: public AActor
{
	GENERATED_BODY()

public:
	ATextureSpeaker();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
