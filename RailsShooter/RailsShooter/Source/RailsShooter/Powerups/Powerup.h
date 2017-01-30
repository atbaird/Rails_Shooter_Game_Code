// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

class APlayerShipNoControlsWithin;

UCLASS()
class RAILSSHOOTER_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY()
		FName meshComponentName = ("StaticMeshComp");
	UPROPERTY()
		FName rootComponentName = ("RootComponent");
	UPROPERTY()
		FName sphereCollisionComponentName = ("Sphere1");

	UPROPERTY()
		bool justSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PowerupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* sphereCollision;

	UPROPERTY(BlueprintReadWrite)
		APlayerShipNoControlsWithin* beingPickedUpBy;

	// Sets default values for this actor's properties
	APowerup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	/** called when something enters sphereCollision */
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves sphereCollision */
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
};
