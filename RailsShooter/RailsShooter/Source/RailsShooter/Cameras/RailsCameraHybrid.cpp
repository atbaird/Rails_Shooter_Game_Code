// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "RailsCameraHybrid.h"


// Sets default values
ARailsCameraHybrid::ARailsCameraHybrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARailsCameraHybrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARailsCameraHybrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


FVector ARailsCameraHybrid::GetCameraWorldPositionC()
{
	return CameraWorldPosition;
}
FVector ARailsCameraHybrid::GetCameraForwardC()
{
	return CameraForward;
}
FVector ARailsCameraHybrid::GetCameraRightC()
{
	return CameraRight;
}
FVector ARailsCameraHybrid::GetCameraUpC()
{
	return CameraUp;
}
float ARailsCameraHybrid::GetCameraOrthoWidthC()
{
	return cameraOrthoWidth;
}
float ARailsCameraHybrid::GetCameraOrthoHeightC()
{
	return cameraAspectRatio;
}
float ARailsCameraHybrid::GetCameraAspectRatioC()
{
	return cameraOrthoHeight;
}