// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "Powerup.h"
#include "../Pawns/PlayerShipNoControlsWithin.h"


// Sets default values
APowerup::APowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	beingPickedUpBy = nullptr;

	justSpawned = true;
	//Create Components
	PowerupMesh = CreateDefaultSubobject<UStaticMeshComponent>(meshComponentName);
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	sphereCollision = CreateDefaultSubobject<USphereComponent>(sphereCollisionComponentName);

	//Attach components to each other
	PowerupMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	sphereCollision->SetupAttachment(RootComponent);


	//SphereCollision Setup.
	sphereCollision->InitSphereRadius(250.0f);
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &APowerup::OnOverlapBegin);       // set up a notification for when this component overlaps something
	sphereCollision->OnComponentEndOverlap.AddDynamic(this, &APowerup::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APowerup::BeginPlay()
{
	Super::BeginPlay();
	beingPickedUpBy = nullptr;
	
}

// Called every frame
void APowerup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APowerup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr || OtherActor->IsPendingKill() == true
		|| IsPendingKill() == true
		|| OtherActor == GetInstigator())
	{
		return;
	}

	if (APlayerShipNoControlsWithin* player = Cast<APlayerShipNoControlsWithin>(OtherActor))
	{
		beingPickedUpBy = player;
	}
}

/** called when something leaves sphereCollision */
void APowerup::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor == nullptr || OtherActor->IsPendingKill() == true
		|| IsPendingKill() == true
		|| OtherActor == GetInstigator())
	{
		return;
	}
	if (APlayerShipNoControlsWithin* player = Cast<APlayerShipNoControlsWithin>(OtherActor))
	{
		beingPickedUpBy = nullptr;
	}
}
