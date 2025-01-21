#include "Item.h"

AItem::AItem()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);
   
    PrimaryActorTick.bCanEverTick = true;
    RotationSpeed = 90.0f;
}


void AItem::BeginPlay()
{
    Super::BeginPlay();

    OnItemPickUP();
}

void AItem::Tick(float DeltaTime) // 1초 / 프레임 = DeltaTime
{
    Super::Tick(DeltaTime);

    if (!FMath::IsNearlyZero(RotationSpeed))
    {
        AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
    }
}

void AItem::ResetActorPosition()
{
    SetActorLocation(FVector::ZeroVector); // 원점
}

float AItem::GetRotationSpeed() const
{
    return RotationSpeed;
}