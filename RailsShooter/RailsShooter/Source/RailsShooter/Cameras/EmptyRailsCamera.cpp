// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "EmptyRailsCamera.h"


// Sets default values
AEmptyRailsCamera::AEmptyRailsCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmptyRailsCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmptyRailsCamera::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

