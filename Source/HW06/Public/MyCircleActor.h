#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCircleActor.generated.h"

UCLASS()
class HW06_API AMyCircleActor : public AActor
{
	GENERATED_BODY()
public:	
	AMyCircleActor();
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ScencComponent")
	USceneComponent* CircleSceneComp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "StaticMeshComponent")
	UStaticMeshComponent* CircleStaticMeshComp;

	FTimerHandle MyTimerHandle;
	float MoveTime;
	float MoveSpeed;
	bool IsVec;

	UFUNCTION()
	void GoStraight(float DeltaTime);

	UFUNCTION()
	void ChangeVector();

public:
	virtual void Tick(float DeltaTime) override;
};
