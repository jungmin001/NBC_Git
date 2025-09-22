// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBox.h"

// Sets default values
AMoveBox::AMoveBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshcomp"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	///Script/Engine.StaticMesh'/Game/Resources/Props/Wall_400x300.Wall_400x300'
	////Script/Engine.StaticMesh'/Game/Resources/Props/SM_Statue.SM_Statue'
	///Script/Engine.Material'/Game/Resources/Materials/M_CobbleStone_Rough.M_CobbleStone_Rough'
	/// /Script/Engine.Material'/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere''

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Statue.SM_Statue"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	RotationSpeed = 30.0f;
}

// Called when the game starts or when spawned
void AMoveBox::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMoveBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorWorldRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

