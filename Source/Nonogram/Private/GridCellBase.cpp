#include "GridCellBase.h"

AGridCellBase::AGridCellBase()
{
	bNetLoadOnClient = false;
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bHighPriority = false;
	
	_defaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = _defaultSceneRoot;
	
	_planeComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	_planeComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	_planeComponent->CastShadow = false;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(
		TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (FoundMesh.Succeeded()) _planeComponent->SetStaticMesh(FoundMesh.Object);
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	_planeComponent->SetRelativeLocation(FVector(0.f, 0.f, 10.f));
	if (FoundMaterial.Succeeded()) _planeComponent->SetMaterial(0, FoundMaterial.Object);
	_planeComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AGridCellBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGridCellBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
