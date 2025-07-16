#include "BigStarPotalActor.h"

ABigStarPotalActor::ABigStarPotalActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationValue = 120.0f;
	StarSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(StarSceneComp);
	StarStaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StarStaticMeshComp->SetupAttachment(StarSceneComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));

	if (StaticMeshAsset.Succeeded())
	{
		StarStaticMeshComp->SetStaticMesh(StaticMeshAsset.Object);
	}
}

void ABigStarPotalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationValue))
	{
		AddActorLocalRotation(FRotator(RotationValue *DeltaTime, 0.0f, 0.0f));
	}
}
