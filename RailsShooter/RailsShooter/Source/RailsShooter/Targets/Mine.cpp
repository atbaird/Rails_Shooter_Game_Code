// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "Mine.h"
#include "../Pawns/PlayerShipNoControlsWithin.h"
#include "../Pawns/EnemyShip.h"
#include "../Obstacles/Obstacle.h"


// Sets default values
AMine::AMine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	justSpawned = true;
	//Create Components
	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(meshComponentName);
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	sphereCollision = CreateDefaultSubobject<USphereComponent>(sphereCollisionComponentName);

	//Attach components to each other
	bulletMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	sphereCollision->SetupAttachment(RootComponent);


	//SphereCollision Setup.
	sphereCollision->InitSphereRadius(250.0f);
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AMine::OnOverlapBegin);       // set up a notification for when this component overlaps something
	sphereCollision->OnComponentEndOverlap.AddDynamic(this, &AMine::OnOverlapEnd);

	//OnActorHit.BindDynamic(this, &AMine::OnMyActorHit);
}

// Called when the game starts or when spawned
void AMine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMine::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	justSpawned = false;
}

void AMine::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
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
		if (player->GetIsInvincible() == true)
		{
			return;
		}
		player->Hurt_Simple_Call();
		DestroyMeNow();
		DestroyMeNow_Implementation();
		return;
	}
	else if (AEnemyShip* enemy = Cast<AEnemyShip>(OtherActor))
	{
		enemy->Hurt_Simple_Call();
		DestroyMeNow();
		DestroyMeNow_Implementation();
		return;
	}
	else if (AObstacle* obstacle = Cast<AObstacle>(OtherActor))
	{
		return;
	}

	if (justSpawned == false)
	{
		OtherActor->Destroy();
		DestroyMeNow();
		DestroyMeNow_Implementation();
	}
}

void AMine::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
void AMine::DestroyMeNow_Implementation()
{
	Destroy();
}