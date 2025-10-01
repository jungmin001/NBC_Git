// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

UCLASS()

class HW_06_API AMyBox : public AActor
{
    GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBox();

protected:

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;

};
