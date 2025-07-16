#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;
class ALongActor;

UCLASS()
class HW06_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();
	FVector ReturnRandomVector();

protected:
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="SceneComp")
	//USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BoxComp")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="Spawn")
	int SpawnNum;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<ALongActor> LongActorClass;

	void SpawnRandomLocation(TSubclassOf<ALongActor>);

};
