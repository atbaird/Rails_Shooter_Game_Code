// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class RAILSSHOOTER_API ABullet : public AActor
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

	UPROPERTY(BlueprintReadWrite)
		float secondsSinceSpawned = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float secondsBeforeDestroySelf = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float bulletMovementSpeed = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector forwardDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* bulletMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* sphereCollision;


	// Sets default values for this actor's properties
	ABullet();

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

	UFUNCTION(BlueprintNativeEvent)
		void DestroyMeNow();
	UFUNCTION(BlueprintCallable, Category = "Bullet")
		virtual void DestroyMeNow_Implementation();

};
