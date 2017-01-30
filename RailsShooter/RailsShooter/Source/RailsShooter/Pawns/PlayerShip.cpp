// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "../Cameras/RailsCamera.h"
#include "PlayerShip.h"

// Sets default values
APlayerShip::APlayerShip()
{
	wantsToShoot = false;
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create our components
	camera = nullptr;
	shipMesh = CreateDefaultSubobject<UStaticMeshComponent>(meshComponentName);
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	shipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Attach components
	//RootComponent->AttachToComponent(shipMesh, FAttachmentTransformRules::KeepRelativeTransform);

	//Possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	wantsToShoot = false;
	for (TObjectIterator<ARailsCamera> Itr; Itr; ++Itr)
	{
		// Access the subclass instance with the * or -> operators.
		camera = *Itr;
		if (camera != nullptr)
		{
			break;
		}
	}

	if (camera == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Camera is null");
		return;
	}

	UpdateImportantVariables();

	FVector myNewPosition = camLoc + (camForward * meshDistanceForwardFromCamera);
	SetActorLocation(myNewPosition);
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (TObjectIterator<ARailsCamera> Itr; Itr; ++Itr)
	{
		// Access the subclass instance with the * or -> operators.
		camera = *Itr;
		if (camera != nullptr)
		{
			break;
		}
	}
	if (camera == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Camera is null");
		return;
	}
	UpdateImportantVariables();
	UpdateScreenPosition();
	HandleMovement();
}

void APlayerShip::UpdateImportantVariables()
{
	if (camera == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Camera is null");
		return;
	}
	camLoc = camera->GetActorLocation();
	camForward = camera->GetActorForwardVector();
	camRight = camera->GetActorRightVector();
	camUp = camera->GetActorUpVector();

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, camRight.ToString());

	width = camera->GetCameraOrthoWidth();
	height = camera->GetCameraOrthoHeight();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::SanitizeFloat(width));
	distForward = camForward * meshDistanceForwardFromCamera;

	halfWidth = width / 2.f;
	halfHeight = height / 2.f;

	relX = ShipScreenPosition.X - halfWidth;
	relY = ShipScreenPosition.Y - halfHeight;

	myNewPosition = camLoc + distForward;
}
void APlayerShip::UpdateScreenPosition()
{
	ShipScreenPosition = ShipScreenPosition + (MovementInput * shipMovementSpeed);

	if (ShipScreenPosition.X < 0.f)
	{
		ShipScreenPosition.X = 0.f;
	}
	else if (ShipScreenPosition.X > width)
	{
		ShipScreenPosition.X = width;
	}
	if (ShipScreenPosition.Y < 0.f)
	{
		ShipScreenPosition.Y = 0.f;
	}
	else if (ShipScreenPosition.Y > height)
	{
		ShipScreenPosition.Y = height;
	}
}
void APlayerShip::HandleMovement()
{
	distRight = camRight * (relX);
	distUp = camUp * (relY);
	

	SetActorLocation(myNewPosition);
	//SetActorRotation(camera->GetActorRotation());
}
// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveUp", this, &APlayerShip::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &APlayerShip::MoveRight);

}


void APlayerShip::MoveRight(float AxisValue)
{
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}
void APlayerShip::MoveUp(float AxisValue)
{
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APlayerShip::Shoot()
{
	wantsToShoot = true;
}
void APlayerShip::DontShoot()
{
	wantsToShoot = false;
}