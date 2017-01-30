// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RailsCameraHybrid.generated.h"

UCLASS()
class RAILSSHOOTER_API ARailsCameraHybrid : public AActor
{
	GENERATED_BODY()

public:

	//Set this to Camera's world position within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CameraWorldPosition;

	//Set this to Camera's Forward within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CameraForward;

	//Set this to Camera's Right within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CameraRight;

	//Set this to Camera's Up within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CameraUp;

	//Set this to Camera's OrthoWidth within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float cameraOrthoWidth;

	//Set this to Camera's AspectRatio within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float cameraAspectRatio;

	//Set this to Camera's OrthoHeight within the blueprint on event tick.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float cameraOrthoHeight;

	// Sets default values for this actor's properties
	ARailsCameraHybrid();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector GetCameraWorldPositionC();
	FVector GetCameraForwardC();
	FVector GetCameraRightC();
	FVector GetCameraUpC();
	float GetCameraOrthoWidthC();
	float GetCameraOrthoHeightC();
	float GetCameraAspectRatioC();

	
};
