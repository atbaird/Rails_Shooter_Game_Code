// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class RAILSSHOOTER_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:
	float RunningTime;
	float originalX;
	float originalY;
	float originalZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	float magnitude = 1.f;
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	
};
