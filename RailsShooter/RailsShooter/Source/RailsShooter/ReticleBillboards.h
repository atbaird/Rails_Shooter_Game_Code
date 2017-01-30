// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "ReticleBillboards.generated.h"

UCLASS()
class RAILSSHOOTER_API AReticleBillboards : public AActor
{
	GENERATED_BODY()

	//http://www.mike-purvis.com/?p=288 <- made in reference to this.
protected:
	UPROPERTY()
		FName rootComponentName = ("RootComponent");
	UPROPERTY()
		FName billboardComponentName = ("BillboardComponent");
	//A UBillboardComponent to hold Icon sprite
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBillboardComponent* BillboardComponent;
	//Sprite for the Billboard Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* SpriteImage;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ToGoOutFrom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float distanceToMaintain;

	// Sets default values for this actor's properties
	AReticleBillboards();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override; //virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override; //TickComponent


	// Begin ActorComponent interface
	//virtual void OnRegister() override;
	
};
