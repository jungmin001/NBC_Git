// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"


// Sets default values
AFloor::AFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneRoot);

	///Script/Engine.StaticMesh'/Game/Resources/Props/Floor_400x400.Floor_400x400'
	///Script/Engine.Material'/Game/Resources/Props/Materials/M_Rock.M_Rock'

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Rock.M_Rock"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, MaterialAsset.Object);
	}

	MoveSpeed = FVector(100.0f, 0.0f, 0.0f);
	MaxRange = 100.0f;

}

void AFloor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AFloor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!MoveSpeed.IsNearlyZero())
	{
		AddActorWorldOffset(FVector(MoveSpeed * DeltaTime));


	}
	if (FVector::Dist(StartLocation, GetActorLocation()) >= MaxRange)
	{
		SetActorLocation(StartLocation);
	}
}

void AFloor::Destroyed()
{
	Super::Destroyed();

	UE_LOG(LogTemp, Warning, TEXT("Destroyed"));
}

void AFloor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));
}

