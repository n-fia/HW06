// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BigStarPotalActor.generated.h"

UCLASS()
class HW06_API ABigStarPotalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABigStarPotalActor();

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ScencComponent")
	USceneComponent* StarSceneComp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "StaticMeshComponent")
	UStaticMeshComponent* StarStaticMeshComp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Rotation")
	float RotationValue;

public:	
	virtual void Tick(float DeltaTime) override;
};
