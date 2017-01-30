// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShipNoControlsWithin.generated.h"

UCLASS()
class RAILSSHOOTER_API APlayerShipNoControlsWithin : public APawn
{
	GENERATED_BODY()

public:

	//HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int currentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxHP;
	UPROPERTY()
		float secondsSinceLastShot;
	UPROPERTY()
		float secondsSinceLastFlippedVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float secondsBeforeStopInvincilityFrames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float secondsBeforeSwitchVisibility;
	bool visible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool invincible;

	//Obstacles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool inObstacle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool justHurtByObstacle;

	UPROPERTY(BlueprintReadWrite)
		int numObstaclesIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canBeDamagedByObstacles;
	UPROPERTY()
		float secondsSinceLastDamagedByObstacle;
	UPROPERTY()
		float secondsBeforeDamageByObstacle;

	// Sets default values for this pawn's properties
	APlayerShipNoControlsWithin();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void SetInObstacle(bool inObst);

	UFUNCTION(BlueprintCallable, Category ="PlayerShipNoControlsWithin")
		void EnteredObstacle();
	UFUNCTION(BlueprintCallable, Category = "PlayerShipNoControlsWithin")
		void ExitedObstacle();

	virtual void Hurt_Simple_Call();
	UFUNCTION(BlueprintNativeEvent)
		void Hurt();
	virtual void Hurt_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Die();
	virtual void Die_Implementation();

	virtual bool GetIsInvincible() const;
	
};
