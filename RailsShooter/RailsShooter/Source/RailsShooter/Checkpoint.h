// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

UCLASS()
class RAILSSHOOTER_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
		FName meshComponentName = ("StaticMeshComp");
	UPROPERTY()
		FName rootComponentName = ("RootComponent");
	UPROPERTY()
		FName sphereActivationCollisionComponentName = ("activationCollision");
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool active;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* CheckpointMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* sphereActivationCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector RelativeCameraPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DistanceBackFromRelForwardToMaintain;

	UPROPERTY()
		bool relPositionSet;



	// Sets default values for this actor's properties
	ACheckpoint();

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

	virtual void SetActive(bool act);

	virtual void RecalRelativeCameraPosition();
};
