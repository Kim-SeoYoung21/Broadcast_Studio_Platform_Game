#include "ActprTest6.h"

AActprTest6::AActprTest6()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion.M_Potion"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 30.0f;
	TransformSpeed = 20.0f;
	SizeSpeed = 1.2f;
}

void AActprTest6::BeginPlay()
{
	Super::BeginPlay();

	FVector NewLocation(200.0f, 300.0f, 300.0f);
	FRotator NewRotation(0.0f, 90.0f, 0.0f);
	FVector NewScale(2.0f);

	FTransform NewTransform(NewRotation, NewLocation, NewScale);

	SetActorTransform(NewTransform);
	
}

void AActprTest6::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	if (!FMath::IsNearlyZero(TransformSpeed))
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, TransformSpeed * DeltaTime));
	}
	if (!FMath::IsNearlyZero(SizeSpeed))
	{
		FVector CurrentScale = GetActorScale3D();

		// 새로운 스케일 계산
		FVector NewScale = CurrentScale + FVector(SizeSpeed * DeltaTime);

		// 스케일 제한 (0.5 ~ 3.0 사이로 제한)
		NewScale = NewScale.GetClampedToSize(0.5f, 20.0f);

		// 새로운 스케일 설정
		SetActorScale3D(NewScale);
	}

}

