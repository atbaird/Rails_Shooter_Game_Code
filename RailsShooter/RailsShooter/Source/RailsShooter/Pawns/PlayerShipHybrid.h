// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShipHybrid.generated.h"

class ARailsCameraHybrid;

UCLASS()
class RAILSSHOOTER_API APlayerShipHybrid : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FName meshComponentName = ("StaticMeshComp");
	UPROPERTY()
		FName rootComponentName = ("RootComponent");
	UPROPERTY()
		FName sphereCollisionComponentName = ("Sphere1");


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* SceneComp;

	//Set mesh to whatever want.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* shipMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* sphereCollision;

	UPROPERTY()
		FVector2D MovementInput = FVector2D(0.f, 0.f);

	//Ship Movement Speed effects however fast the ship moves about screen position based on player input.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float shipMovementSpeed = 80.f;

	//meshDistanceForwardFromCamera effects how far forward from a given hybrid camera it will place itself.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float meshDistanceForwardFromCamera = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ARailsCameraHybrid* camera;

	UPROPERTY(BlueprintReadWrite)
		bool wantsToShoot;

	FVector2D shipScreenPosition;


	// Sets default values for this pawn's properties
	APlayerShipHybrid();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	void PutAtCameraCenter();

	//Input Functions
	void MoveUp(float AxisValue);
	void MoveRight(float AxisValue);
	void Shoot();
	void DontShoot();


	//Collision
	/** called when something enters sphereCollision */
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves sphereCollision */
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
