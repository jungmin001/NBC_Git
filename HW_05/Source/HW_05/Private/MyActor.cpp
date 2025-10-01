#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false;

    CurrentLocation = FVector2D(0.f, 0.f);
    MoveCount = 0;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Start Location = %f, %f"),
        CurrentLocation.X, CurrentLocation.Y);
    Move();
    UE_LOG(LogTemp, Warning, TEXT("End Location = %f, %f"),
        CurrentLocation.X, CurrentLocation.Y);
}

int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
    for (int32 i = 0; i < 10; i++)
    {
        CurrentLocation.X += Step();
        CurrentLocation.Y += Step();

        UE_LOG(LogTemp, Warning, TEXT("Step %d = %f, %f"), i+1,
            CurrentLocation.X, CurrentLocation.Y);
    }
}