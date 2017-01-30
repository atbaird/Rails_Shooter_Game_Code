// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class RAILSSHOOTER_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:

	//The Two test cameras in our scene.
	UPROPERTY(EditAnywhere)
		TArray<AActor*> Cameras;
	//AActor* CameraOne;
	UPROPERTY(EditAnywhere)
		int currentIndex = 0;
	UPROPERTY(EditAnywhere)
		bool active = false;

	//UPROPERTY(EditAnywhere)
	//AActor* CameraTwo;

	//Time before change to next camera.
	float TimeToNextCameraChange;

	// Sets default values for this actor's properties
	ACameraDirector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
};
