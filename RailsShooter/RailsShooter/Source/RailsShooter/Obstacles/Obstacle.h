// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class RAILSSHOOTER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canBeHurt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int currentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxHP;

	UPROPERTY()
		float secondsSinceLastHurt;
	UPROPERTY()
		float secondsBeforeFlipBackOn;
	UPROPERTY()
		float secondsSinceLastFlipped;
	UPROPERTY()
		float secondsBeforeStopBlinking;

	UPROPERTY()
		bool dead;

	UPROPERTY()
		bool invisible;

	// Sets default values for this actor's properties
	AObstacle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Obstacle")
	virtual void Damage();
};
