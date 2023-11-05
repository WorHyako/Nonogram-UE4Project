#include "TextureReader.h"

ATextureReader::ATextureReader()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATextureReader::BeginPlay()
{
	Super::BeginPlay();
}

void ATextureReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ATextureReader::ScanTexture()
{
	const FColor* FormatedImageData;
	if (_texture2D != nullptr)
	{
		_textureSizeX = _texture2D->GetSizeX();
		_textureSizeY = _texture2D->GetSizeY();
		delete _whiteIndexMatrix;
		_whiteIndexMatrix = new bool*[_textureSizeX];
		for (int i = 0; i < _textureSizeX; i++)
		{
			_whiteIndexMatrix[i] = new bool[_textureSizeY];
			for (int j = 0; j < _textureSizeY; j++)
				_whiteIndexMatrix[i][j] = false;
		}
		TextureCompressionSettings originCompressionSettings = _texture2D->CompressionSettings;
		TextureMipGenSettings originMipSettings = _texture2D->MipGenSettings;
		bool originSrgb = _texture2D->SRGB;
		_texture2D->CompressionSettings = TC_VectorDisplacementmap;
		_texture2D->MipGenSettings = TMGS_NoMipmaps;
		_texture2D->SRGB = false;
		_texture2D->UpdateResource();
		FormatedImageData = static_cast<const FColor*>(_texture2D->PlatformData->Mips[0].BulkData.LockReadOnly());
		for (int x = 0; x < _textureSizeX; x++)
			for (int y = 0; y < _textureSizeY; y++)
			{
				//_pixelArray.Add(FormatedImageData[y * _textureSizeX + x]);
				if (FormatedImageData[y * _textureSizeX + x].R > 200)
				{
					//_whiteIndexes.Add(_textureSizeY * x + y);
					_whiteIndexMatrix[y][_textureSizeY - 1 - x] = true;
				}
			}
		_texture2D->PlatformData->Mips[0].BulkData.Unlock();
		_texture2D->CompressionSettings = originCompressionSettings;
		_texture2D->MipGenSettings = originMipSettings;
		_texture2D->SRGB = originSrgb;
		_texture2D->UpdateResource();
		return true;
	}
	return false;
}

bool ATextureReader::LoadTexture(FString path_)
{
	_texture2D = nullptr;
	_texture2D = LoadObject<UTexture2D>(NULL, *path_);
	if (_texture2D)
	{
		_textureValid = true;
		return true;
	}
	return false;
}
