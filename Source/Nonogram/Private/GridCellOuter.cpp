#include "GridCellOuter.h"

AGridCellOuter::AGridCellOuter()
{
	_textRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender Number"));
	_textRenderComponent->SetRelativeRotation(FRotator(90.f,90.f,0.f));
	_textRenderComponent->SetRelativeLocation(FVector(0.f,0.f,15.f));
	_textRenderComponent->HorizontalAlignment = EHTA_Center;
	_textRenderComponent->VerticalAlignment = EVRTA_TextCenter;
	_textRenderComponent->WorldSize = 70;
	_textRenderComponent->Text = FText::FromString("-");
	static ConstructorHelpers::FObjectFinder<UMaterial> textMaterial(
		TEXT("/Game/Materials/M_CellsNumberFont.M_CellsNumberFont"));
	if (textMaterial.Succeeded()) _textRenderComponent->SetTextMaterial(textMaterial.Object);
	_textRenderComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AGridCellOuter::BeginPlay()
{
	Super::BeginPlay();
}
