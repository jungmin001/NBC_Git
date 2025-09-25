#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTest, Warning, All);

UCLASS()
class CH3_01_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:

	USceneComponent* SceneRoot;

	UStaticMeshComponent* StaticMeshComp;
	
	float RotationSpeed;

	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	//UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	//void ResetActorPosition();

	//UFUNCTION(BlueprintPure, Category = "Item|Properties")
	//float GetRotationSpeed() const;

	//UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	//void OnItemPickUP();
};
