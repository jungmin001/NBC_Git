// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveBox.generated.h"

UCLASS()
class HW_06_API AMoveBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveBox();

protected:
	UPROPERTY()
	USceneComponent* SceneRoot;
	UPROPERTY()
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Item|Properties")
	float RotationSpeed = 90.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
