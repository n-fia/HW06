#include "MyCircleActor.h"

AMyCircleActor::AMyCircleActor()
{
	IsVec = true;
	MoveTime = 10.0f;
	MoveSpeed = 500.0f;
	PrimaryActorTick.bCanEverTick = true;
	CircleSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(CircleSceneComp);
	CircleStaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	CircleStaticMeshComp->SetupAttachment(CircleSceneComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));

	if(StaticMeshAsset.Succeeded())
	{
		CircleStaticMeshComp->SetStaticMesh(StaticMeshAsset.Object);
	}
}

void AMyCircleActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		MyTimerHandle,
		this,
		&AMyCircleActor::ChangeVector,
		MoveTime,
		true
	);
}

void AMyCircleActor::GoStraight(float DeltaTime) {
	AddActorLocalOffset(FVector(0.0f, -MoveSpeed* DeltaTime, 0.0f));
}

void AMyCircleActor::ChangeVector() {
	if (IsVec)
	{
		IsVec = false;
		MoveSpeed *= -1;
	}
	else
	{
		IsVec = true;
		MoveSpeed *= -1;
	}
}

void AMyCircleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GoStraight(DeltaTime);
}