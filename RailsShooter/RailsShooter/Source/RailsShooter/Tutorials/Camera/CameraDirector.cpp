// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "CameraDirector.h"


//gives access to some useful general-purpose functions
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Causes us to switch views between the two Cameras every 3 seconds:
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	if (active == false)
	{
		TimeToNextCameraChange = TimeBetweenCameraChanges;
		return;
	}
	TimeToNextCameraChange -= DeltaTime;
	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (currentIndex == Cameras.Num() - 1)
			{
				currentIndex = 0;
			}
			else
			{
				currentIndex++;
			}
			OurPlayerController->SetViewTargetWithBlend(Cameras[currentIndex], SmoothBlendTime);
			//if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			//{
			//	// Cut instantly to camera one.
			//	OurPlayerController->SetViewTarget(CameraOne);
			//}
			//else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			//{
			//	// Blend smoothly to camera two.
			//	OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			//}
		}
	}
}

