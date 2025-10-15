#include "MyPawn.h"
#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComp->InitCapsuleSize(100.f, 100.f);
	CapsuleComp->SetCollisionProfileName(TEXT("Pawn"));
	SetRootComponent(CapsuleComp);

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowComp->SetupAttachment(CapsuleComp);

	SkeletalComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalComp->SetupAttachment(CapsuleComp);


	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 300.f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	NormalSpeed = 600.0f;
	SprintSpeedMultiplier = 2.0f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;
	GravityScale = 2.0f;
	VelocityZ;
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Move);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Look);
			}

			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::StartSprint);

				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&AMyPawn::StopSprint);
			}
		}
	}
}

void AMyPawn::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	FVector2D MoveInput = value.Get<FVector2D>();
	const float DeltaTime = GetWorld()->GetDeltaSeconds();


	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddActorLocalOffset(GetActorForwardVector() * (MoveInput.X * NormalSpeed * DeltaTime));
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddActorLocalOffset(GetActorRightVector() * (MoveInput.Y * NormalSpeed * DeltaTime));
	}
}

void AMyPawn::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();
	FRotator LookRotation = FRotator(0.0f, LookInput.X, 0.0f);
	AddActorLocalRotation(LookRotation * 2.5f);

	AddControllerYawInput(LookInput.X / 0.5f);
	AddControllerPitchInput(LookInput.Y);

	const float MeshYawSpeed = 150.0f;

	if (!FMath::IsNearlyZero(LookInput.X))
	{
		FRotator YawRot(0.0f, LookInput.X * MeshYawSpeed * GetWorld()->GetDeltaSeconds(), 0.0f);
		SkeletalComp->AddLocalRotation(YawRot);
	}
}  

void AMyPawn::StartSprint(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		NormalSpeed = SprintSpeed;
	}
}

void AMyPawn::StopSprint(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		NormalSpeed = 600.0f;
	}
}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Gravity = FVector(0.0f, 0.0f, -500.0f * GravityScale * DeltaTime);
	AddActorWorldOffset(Gravity, true);
}
