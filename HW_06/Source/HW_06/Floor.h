// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()

class HW_06_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Item|Properties")
 	FVector MoveSpeed = FVector(0.0f);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Item|Properties")
	float MaxRange = 100.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Item|Properties")
	FVector StartLocation;

	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
