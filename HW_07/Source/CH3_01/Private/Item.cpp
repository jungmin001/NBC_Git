#include "Item.h"

DEFINE_LOG_CATEGORY(LogTest)

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	///Script/Engine.StaticMesh'/Game/Resources/Props/SM_Star_B.SM_Star_B'
	///Script/Engine.Material'/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere'

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/Resources/Props/SM_Star_B.SM_Star_B'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}


	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(LogTest, Warning, TEXT("%s PostInitializeComponents"), *GetName());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	/*SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
	SetActorRotation(FRotator(45.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f, 3.0f, 2.0f));*/

	UE_LOG(LogTest, Warning, TEXT("%s BeginPlay"), *GetName());
}


void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogTest, Warning, TEXT("%s EndPlay"), *GetName());
}

void AItem::Destroyed()
{
	Super::Destroyed();
	UE_LOG(LogTest, Warning, TEXT("%s Destroyed"), *GetName());
}

//OnItemPickUP();
//}


