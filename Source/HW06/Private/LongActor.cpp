#include "LongActor.h"

ALongActor::ALongActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RotationValue = 30.0f;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/Resources/Props/Pillar_50x500.Pillar_50x500"));
	
	if (StaticMeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMeshAsset.Object);
		UE_LOG(LogTemp, Warning, TEXT("SetStaticMesh Is Succeeded"));
	}
}

void ALongActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, RotationValue*DeltaTime,0.0f));
}

FRotator ALongActor::GetStartRandomRotator()
{
	FRotator StartRotation = FRotator(0.0f, FMath::FRand()*180.0f, 0.0f);
	return StartRotation;
}

