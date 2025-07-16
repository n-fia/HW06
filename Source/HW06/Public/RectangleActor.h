#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RectangleActor.generated.h"

UCLASS()
class HW06_API ARectangleActor : public AActor
{
	GENERATED_BODY()

public:
	ARectangleActor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SceneComp")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "StaticMeshComp")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Speed")
	float UpDwanSpeedZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float MaxRange;

	FVector StartActorLocation;
	FVector NowLocation;
	FVector DeltaLocation;

public:
	virtual void Tick(float DeltaTime) override;
};
