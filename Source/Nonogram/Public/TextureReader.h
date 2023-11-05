#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TextureReader.generated.h"

UCLASS()
class NONOGRAM_API ATextureReader
	: public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* _texture2D = nullptr;

	bool _textureValid = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _textureSizeX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int _textureSizeY;
	
	TArray<FColor> _pixelArray;

	bool**_whiteIndexMatrix;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> _whiteIndexes;
	
	ATextureReader();

	UFUNCTION(BlueprintCallable)
	bool ScanTexture();
	
	UFUNCTION(BlueprintCallable)
	bool LoadTexture(FString path_);
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
