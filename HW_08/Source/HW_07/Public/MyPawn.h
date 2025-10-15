#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UArrowComponent;
struct FInputActionValue;

UCLASS()
class HW_07_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SkeletalMesh")
	USkeletalMeshComponent* SkeletalComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arrow")
	UArrowComponent* ArrowComp;


protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);
	UPROPERTY()
	float VelocityZ;

	void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float NormalSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeedMultiplier;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpHeight;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float GravityScale;

};
