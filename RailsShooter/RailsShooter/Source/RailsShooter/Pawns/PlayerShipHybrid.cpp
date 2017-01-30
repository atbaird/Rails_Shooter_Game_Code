// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "PlayerShipHybrid.h"


// Sets default values
APlayerShipHybrid::APlayerShipHybrid()
	: camera(nullptr),
	shipScreenPosition(0.f, 0.f)
{
	wantsToShoot = false;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	shipMesh = CreateDefaultSubobject<UStaticMeshComponent>(meshComponentName);
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	sphereCollision = CreateDefaultSubobject<USphereComponent>(sphereCollisionComponentName);

	shipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	sphereCollision->SetupAttachment(RootComponent);


	sphereCollision->InitSphereRadius(250.0f);
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &APlayerShipHybrid::OnOverlapBegin);       // set up a notification for when this component overlaps something
	sphereCollision->OnComponentEndOverlap.AddDynamic(this, &APlayerShipHybrid::OnOverlapEnd);

	//Possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlayerShipHybrid::BeginPlay()
{
	Super::BeginPlay();
	wantsToShoot = false;
	
}

// Called every frame
void APlayerShipHybrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (camera != nullptr)
	{

	}
}

// Called to bind functionality to input
void APlayerShipHybrid::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void APlayerShipHybrid::PutAtCameraCenter()
{
	if (camera == nullptr)
	{
		return;
	}
	//float orthoHeight = camera->GetCameraOrthoHeightC();
	//float orthoWidth = camera->GetCameraOrthoWidthC();
}

//Input Functions
void APlayerShipHybrid::MoveUp(float AxisValue)
{
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}
void APlayerShipHybrid::MoveRight(float AxisValue)
{
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APlayerShipHybrid::Shoot()
{
	wantsToShoot = true;
}
void APlayerShipHybrid::DontShoot()
{
	wantsToShoot = false;
}

//Collision


void APlayerShipHybrid::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr || OtherActor->IsPendingKill() == true
		|| IsPendingKill() == true
		|| OtherActor == GetInstigator())
	{
		return;
	}
}

void APlayerShipHybrid::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}