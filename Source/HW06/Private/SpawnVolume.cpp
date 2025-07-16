#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "LongActor.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnNum = 5;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
}

void ASpawnVolume::BeginPlay()
{
	for (int i = 0; i < SpawnNum; ++i) 
	{
		SpawnRandomLocation(LongActorClass);
	}
}

FVector ASpawnVolume::ReturnRandomVector()
{
	FVector BoxExtent = BoxComponent->GetScaledBoxExtent();
	FVector BoxCenterLocation = BoxComponent->GetComponentLocation();

	return BoxCenterLocation + FVector(0.0f,
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));
}

void ASpawnVolume::SpawnRandomLocation(TSubclassOf<ALongActor> LongActor)
{
	if (LongActor)
	{
		GetWorld()->SpawnActor<ALongActor>(LongActor, ReturnRandomVector(), ALongActor::GetStartRandomRotator());
	}
}