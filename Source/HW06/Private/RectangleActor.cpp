#include "RectangleActor.h"

ARectangleActor::ARectangleActor()
{
	PrimaryActorTick.bCanEverTick = true;
	UpDwanSpeedZ = FMath::FRandRange(500.0f,1000.0f);
	MaxRange = 500.0f;
	DeltaLocation = FVector(0.0f, 0.0f, UpDwanSpeedZ);
	NowLocation = FVector(0.0f, 0.0f, 0.0f);

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SetStaticMeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (SetStaticMeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(SetStaticMeshAsset.Object);
	}
}

void ARectangleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(DeltaLocation* DeltaTime);
	NowLocation += DeltaLocation * DeltaTime;
	if (DeltaLocation.Z > 0.0f && NowLocation.Z >= MaxRange)
	{
		DeltaLocation *= -1;
	}
	else if (DeltaLocation.Z<0.0f && NowLocation.Z <= 0.0f)
	{
		DeltaLocation *= -1;
	}
}