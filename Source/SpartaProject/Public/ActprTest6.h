#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActprTest6.generated.h"

UCLASS()
class SPARTAPROJECT_API AActprTest6 : public AActor
{
	GENERATED_BODY()
	
public:	

	AActprTest6();

protected:

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;
	float TransformSpeed;
	float SizeSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
