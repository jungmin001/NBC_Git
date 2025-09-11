#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CurrentLocation = FVector2D(0.f, 0.f);
	MoveCount = 0;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("[Start] Pos=(%d, %d)"),
		(int32)CurrentLocation.X, (int32)CurrentLocation.Y);

	Move();

	UE_LOG(LogTemp, Warning, TEXT("[End]   Pos=(%d, %d)"),
		(int32)CurrentLocation.X, (int32)CurrentLocation.Y);
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
	for (int32 i = 0; i < 10; i++)
	{
		const int32 PrevX = (int32)CurrentLocation.X;
		const int32 PrevY = (int32)CurrentLocation.Y;

		CurrentLocation.X += Step();
		CurrentLocation.Y += Step();

		UE_LOG(LogTemp, Warning,
			TEXT("[Step %02d] Pos=(%d, %d) \xCE\x94=(%+d, %+d)"),
			i + 1,
			(int32)CurrentLocation.X, (int32)CurrentLocation.Y,
			(int32)CurrentLocation.X - PrevX, (int32)CurrentLocation.Y - PrevY);
	}
}
