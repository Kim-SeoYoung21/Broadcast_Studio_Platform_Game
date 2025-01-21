#pragma once

#include "CoreMinimal.h" 
#include "GameFramework/Actor.h" 
#include "Item.generated.h" 
 

UCLASS() 
class SPARTAPROJECT_API AItem : public AActor 
{
	GENERATED_BODY()
	
public:	
	
	AItem();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	USceneComponent* SceneRoot; // 멤버 포인터 형태로 선언

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Item|Action")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category="Item|Properties") //리턴값만 반환
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Itme|Event") //구현은 BP, 호출은 CPP에서 가능
	void OnItemPickUP();
};
