#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LongActor.generated.h"

UCLASS()
class HW06_API ALongActor : public AActor
{
	GENERATED_BODY()
	
public:
	ALongActor();

	static FRotator GetStartRandomRotator();
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SceneCompnent")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshCompnent")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationValue;

public:	
	virtual void Tick(float DeltaTime) override;
};
