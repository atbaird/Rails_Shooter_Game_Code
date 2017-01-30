// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "TestPawn.h"

// Sets default values
ATestPawn::ATestPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->AttachTo(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->AttachTo(RootComponent);
	timeSecondsMoveXNotEqual0 = 0.f;
	timeSecondsMoveYNotEqual0 = 0.f;
	MaxVelocity = 100.f;
	acceleration = 60.f;
	deceleration = acceleration;
}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Do something based on player input.
	// Handle growing and shrinking based on our "Grow" action
	{
		float CurrentScale = OurVisibleComponent->GetComponentScale().X;
		if (bGrowing)
		{
			// Grow to double size over the course of one second
			CurrentScale += DeltaTime;
		}
		else
		{
			// Shrink half as fast as we grow
			CurrentScale -= (DeltaTime * 0.5f);
		}
		// Make sure we never drop below our starting size, or increase past double size.
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (FMath::Abs(DirectionHeldDown.X) > 0.f)
		{
			float posDir = (DirectionHeldDown.X / FMath::Abs(DirectionHeldDown.X));
			CurrentVelocity.X += (acceleration * posDir * DeltaTime);
		}
		else if (FMath::Abs(CurrentVelocity.X) > 0.f)
		{
			FVector normVel = CurrentVelocity;
			normVel.Normalize();
			float cur = CurrentVelocity.X;
			float posDir = (normVel.X / FMath::Abs(normVel.X));
			CurrentVelocity.X -= (deceleration * posDir * DeltaTime);
			if ((CurrentVelocity.X < 0.f && cur > 0.f)
				|| (CurrentVelocity.X > 0.f && cur < 0.f))
			{
				CurrentVelocity.X = 0.f;
			}
		}
		if (FMath::Abs(DirectionHeldDown.Y) > 0.f)
		{
			float posDir = (DirectionHeldDown.Y / FMath::Abs(DirectionHeldDown.Y));
			CurrentVelocity.Y += (acceleration * posDir * DeltaTime);
		}
		else if (FMath::Abs(CurrentVelocity.Y) > 0.f)
		{
			FVector normVel = CurrentVelocity;
			normVel.Normalize();
			float cur = CurrentVelocity.Y;
			float posDir = (normVel.Y / FMath::Abs(normVel.Y));
			CurrentVelocity.Y -= (deceleration * posDir * DeltaTime);
			if ((CurrentVelocity.Y < 0.f && cur > 0.f)
				|| (CurrentVelocity.Y > 0.f && cur < 0.f))
			{
				CurrentVelocity.Y = 0.f;
			}
		}
		FVector xyOnly = CurrentVelocity;
		xyOnly.Z = 0.f;
		float xyLen = xyOnly.Size();
		if (xyLen > MaxVelocity)
		{
			xyOnly.Normalize();
			xyOnly *= MaxVelocity;
			CurrentVelocity.X = xyOnly.X;
			CurrentVelocity.Y = xyOnly.Y;
		}

		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}
}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Enable Movement controls from the tutorial; ie Grow, MoveX, and MoveY.

	// Respond when our "Grow" key is pressed or released.
	InputComponent->BindAction("Grow", IE_Pressed, this, &ATestPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &ATestPawn::StopGrowing);

	// Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
	InputComponent->BindAxis("MoveX", this, &ATestPawn::Move_XAxis); //must be specifically called after the input variable.
	InputComponent->BindAxis("MoveY", this, &ATestPawn::Move_YAxis);
}


//Four new functions:
void ATestPawn::Move_XAxis(float AxisValue)
{
	//Have to clamp if planning on having more than just W key for up direction.
	// Move at 100 units per second forward or backward
	//CurrentVelocity.X
	DirectionHeldDown.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void ATestPawn::Move_YAxis(float AxisValue)
{
	// Move at 100 units per second right or left
	//CurrentVelocity.Y
	DirectionHeldDown.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void ATestPawn::StartGrowing()
{
	bGrowing = true;
}

void ATestPawn::StopGrowing()
{
	bGrowing = false;
}