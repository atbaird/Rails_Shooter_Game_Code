// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RailsCamera.generated.h"

UCLASS()
class RAILSSHOOTER_API ARailsCamera : public AActor
{
	GENERATED_BODY()

public:

	UCameraComponent* OurCamera;

	// Sets default values for this actor's properties
	ARailsCamera();

	UPROPERTY(EditAnywhere)
		float MovementSpeedMultiplier = 1.f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent)
		float GetCameraOrthoWidth();
	virtual float GetCameraOrthoWidth_Implementation();

	UFUNCTION(BlueprintImplementableEvent)
		float GetCameraOrthoHeight();
	virtual float GetCameraOrthoHeight_Implementation();

};
