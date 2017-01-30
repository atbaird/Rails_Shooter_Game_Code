// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TestPawn.generated.h"

UCLASS()
class RAILSSHOOTER_API ATestPawn : public APawn
{
	GENERATED_BODY()

public:
	//Added in order to keep track of what components we create for this pawn:
	UPROPERTY(EditAnywhere)	USceneComponent* OurVisibleComponent; //Variable is set as a UProperty
																  //This means viewable from Unreal Engine scene view, also means that that it is prevents variable from being reset when game launches
																  //or when project/level reloaded.
																  //Input variables
	FVector CurrentVelocity;
	float MaxVelocity;
	float deceleration;
	float acceleration;
	FVector DirectionHeldDown;
	bool bGrowing = false;
	float timeSecondsMoveXNotEqual0;
	float timeSecondsMoveYNotEqual0;


	// Sets default values for this pawn's properties
	ATestPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	//Input functions
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();
};
