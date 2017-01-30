// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "EnemyShip.generated.h"



UCLASS()
class RAILSSHOOTER_API AEnemyShip : public APawn
{
	GENERATED_BODY()

public:
	//Movement

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool paused;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool constantlyMoveForwardIfUnpaused;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float movementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float secondsPassedWhileUnpaused;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> secondsBeforeTurn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FRotator> rotationToTake;
	UPROPERTY()
		FRotator rotationToTurnTowards;


	//Shooting
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool loopShootingPattern;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> secondsBeforeFireWhileUnpausedLoop;
	UPROPERTY()
		TArray<float> secondsBeforeFireWhileUnpaused;
	UPROPERTY()
		TArray<bool> fired;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float additionalDelayAfterFirstFiringLoop;
	UPROPERTY()
		bool setUpOnce;
	//This will basically make the ship operate like a turret, if on.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool lookAtTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float targetLookAtRadius;
	UPROPERTY(BlueprintReadWrite)
		AActor* nearestTarget;
	UPROPERTY()
		FRotator originalRotation;

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

	//Obstacles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool inObstacle;

	UPROPERTY(BlueprintReadWrite)
		int numObstaclesIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canBeDamagedByObstacles;

	// Sets default values for this pawn's properties
	AEnemyShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void FindNearestValidTarget();
	virtual void RotationUpdate(float DeltaSeconds);
	virtual void MoveForwardUpdate(float DeltaSeconds);
	virtual void FireUpdate(float DeltaSeconds);


	UFUNCTION(BlueprintNativeEvent)
		void Fire();
	virtual void Fire_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Unpause();
	virtual void Unpause_Implementation();
	
	UFUNCTION(BlueprintNativeEvent)
		void Pause();
	virtual void Pause_Implementation();

	virtual void SetInObstacle(bool inObst);

	UFUNCTION(BlueprintCallable, Category = "EnemyShip")
		void EnteredObstacle();
	UFUNCTION(BlueprintCallable, Category = "EnemyShip")
		void ExitedObstacle();

	virtual void Hurt_Simple_Call();
	UFUNCTION(BlueprintNativeEvent)
		void Hurt();
	virtual void Hurt_Implementation();

	UFUNCTION(BlueprintNativeEvent)
		void Die();
	virtual void Die_Implementation();

	void CopyFireTimers();
	
};
