// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "Bullet.h"
#include "../Pawns/PlayerShipNoControlsWithin.h"
#include "../Pawns/EnemyShip.h"
#include "../Obstacles/Obstacle.h"
#include "Mine.h"


// Sets default values
ABullet::ABullet()
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
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlapBegin);       // set up a notification for when this component overlaps something
	sphereCollision->OnComponentEndOverlap.AddDynamic(this, &ABullet::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	forwardDirection = FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X);
}

// Called every frame
void ABullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	secondsSinceSpawned += DeltaTime;
	if (secondsSinceSpawned >= secondsBeforeDestroySelf)
	{
		DestroyMeNow_Implementation();
	}
	justSpawned = false;

	FVector loc = GetActorLocation();
	FVector movement = (forwardDirection * DeltaTime * bulletMovementSpeed);
	SetActorLocation(loc + movement);
}

void ABullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr || OtherActor->IsPendingKill() == true
		|| IsPendingKill() == true
		|| OtherActor == GetInstigator())
	{
		return;
	}
	if (ABullet* otherBullet = Cast<ABullet>(OtherActor))
	{
		if (otherBullet->GetInstigator() == GetInstigator())
		{
			return;
		}
	}
	else if (APlayerShipNoControlsWithin* player = Cast<APlayerShipNoControlsWithin>(OtherActor))
	{
		if (player != GetInstigator())
		{
			if (player->GetIsInvincible() == true)
			{
				return;
			}
			player->Hurt_Simple_Call();
			DestroyMeNow_Implementation();
			return;
		}
		return;
	}
	else if (AEnemyShip* enemy = Cast<AEnemyShip>(OtherActor))
	{
		if (Cast<AEnemyShip>(GetInstigator()))
		{
		}
		else
		{
			enemy->Hurt_Simple_Call();
			DestroyMeNow_Implementation();
			return;
		}
		return;
	}
	else if (AObstacle* obstacle = Cast<AObstacle>(OtherActor))
	{
		obstacle->Damage();
		DestroyMeNow_Implementation();
	}
	else if (AMine* mine = Cast<AMine>(OtherActor))
	{
		OtherActor->Destroy();
		DestroyMeNow_Implementation();
	}
}
void ABullet::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ABullet::DestroyMeNow_Implementation()
{
	DestroyMeNow();
	Destroy();
}