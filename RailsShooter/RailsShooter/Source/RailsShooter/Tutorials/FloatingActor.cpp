// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	FVector CurrentLocation = GetActorLocation();
	originalX = CurrentLocation.X;
	originalY = CurrentLocation.Y;
	originalZ = CurrentLocation.Z;

}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//This chunk of code will cause the actor associated to this c++ code to bob up and down smoothly using RunningTime.
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f * magnitude;       //Scale our height by a factor of 20
	RunningTime += DeltaTime;

	//Add periodic motion on the X and/or Y axis, and multiply the DeltaTime value by a number between 0.6 and 1.4,
	//so your FloatingActor appears to float around freely. This can look great for powerups!
	float deltaDiff = DeltaTime * 1.4f;
	NewLocation.Y += ((deltaDiff));

	SetActorLocation(NewLocation);
}

