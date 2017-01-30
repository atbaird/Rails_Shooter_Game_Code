// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

class ARailsCamera;

UCLASS()
class RAILSSHOOTER_API APlayerShip : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		FName meshComponentName = ("StaticMeshComp");
	UPROPERTY()
		FName rootComponentName = ("RootComponent");
	UPROPERTY()
		FName sphereCollisionComponentName = ("Sphere1");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ARailsCamera* camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float meshDistanceForwardFromCamera = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float shipMovementSpeed = 80.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* shipMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
		USceneComponent* SceneComp;

	UPROPERTY(BlueprintReadWrite)
		bool wantsToShoot;
	
	UPROPERTY()
	float height = 0.f;

	UPROPERTY()
	float width = 0.f;

	UPROPERTY()
	float halfWidth = 0.f;

	UPROPERTY()
	float halfHeight = 0.f;

	UPROPERTY()
		float relX = 0.f;

	UPROPERTY()
		float relY = 0.f;

	UPROPERTY()
	FVector camLoc = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector camForward = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector camRight = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector camUp = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector myNewPosition = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector distForward = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector distRight = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector distUp = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	FRotator MaxShipPitchYaw = FRotator(0.f, 40.f, 40.f);

	UPROPERTY()
	FRotator MaxCameraPitchYaw = FRotator(0.f, 45.f, 45.f);

	UPROPERTY()
	FRotator CameraRotation = FRotator(0.f, 0.f, 0.f);

	UPROPERTY()
	FRotator ShipRotation = FRotator(0.f, 0.f, 0.f);

	UPROPERTY()
	FVector2D MovementInput = FVector2D(0.f, 0.f);

	UPROPERTY()
	FVector2D MaxShipConstraintsFromEdgesOfScreen = FVector2D(100.f, 80.f);

	UPROPERTY()
	FVector2D ShipScreenPosition = FVector2D(0.f, 0.f);
public:
	// Sets default values for this pawn's properties
	APlayerShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Input Functions
	void UpdateImportantVariables();
	void UpdateScreenPosition();
	void HandleMovement();
	void MoveUp(float AxisValue);
	void MoveRight(float AxisValue);
	void Shoot();
	void DontShoot();

};
