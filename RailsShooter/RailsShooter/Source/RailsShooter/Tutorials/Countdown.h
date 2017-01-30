// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class RAILSSHOOTER_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:
	//Timer and Events specific code

	//Adding comments immediately above a UPROPERTY with no empty lines between makes said comment line visible from Level editor! :D

	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
		int32 CountdownTime;
	UTextRenderComponent* CountdownText;
	FTimerHandle CountdownTimerHandle;

	void UpdateTimerDisplay();
	void AdvanceTimer();

	//UFUNCTION Exposes the function to UE4.
	//However, you need to make some changes to enable this.
	//So for a function that you want exposed to UE4, define it as a UFunction, leave it undefined, then create a virtual function that
	//has the same name but also has _Implementation() at the end instead.
	//Doing this enables us to receive information from the C++ script.

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();


	// Sets default values for this actor's properties
	ACountdown();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	
};
