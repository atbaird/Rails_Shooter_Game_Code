// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "PlayerShipNoControlsWithin.h"


// Sets default values
APlayerShipNoControlsWithin::APlayerShipNoControlsWithin()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	maxHP = 3;
	secondsBeforeStopInvincilityFrames = 3.f;
	secondsBeforeSwitchVisibility = 0.1f;
	invincible = false;
	canBeDamagedByObstacles = true;
	justHurtByObstacle = false;
	numObstaclesIn = 0;
	secondsBeforeDamageByObstacle = secondsBeforeStopInvincilityFrames + 0.1f;
}

// Called when the game starts or when spawned
void APlayerShipNoControlsWithin::BeginPlay()
{
	Super::BeginPlay();
	if (maxHP <= 0)
	{
		maxHP = 1;
	}
	currentHP = maxHP;
	secondsSinceLastShot = secondsBeforeStopInvincilityFrames;
	secondsSinceLastFlippedVisibility = 0.f;
	visible = true;
	invincible = false;
	inObstacle = false;
	numObstaclesIn = 0;
	secondsSinceLastDamagedByObstacle = secondsBeforeDamageByObstacle;
	justHurtByObstacle = false;
}

// Called every frame
void APlayerShipNoControlsWithin::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	justHurtByObstacle = false;
	if (secondsSinceLastDamagedByObstacle < secondsBeforeDamageByObstacle)
	{
		secondsSinceLastDamagedByObstacle += DeltaTime;
	}
	if (inObstacle)
	{
		if (secondsSinceLastDamagedByObstacle >= secondsBeforeDamageByObstacle)
		{
			secondsSinceLastDamagedByObstacle = 0.f;
			Hurt_Simple_Call();
			justHurtByObstacle = true;
		}
	}
	if (secondsSinceLastShot < secondsBeforeStopInvincilityFrames)
	{
		invincible = true;
		secondsSinceLastShot += DeltaTime;
		secondsSinceLastFlippedVisibility += DeltaTime;
		if (secondsSinceLastFlippedVisibility >= secondsBeforeSwitchVisibility)
		{
			secondsSinceLastFlippedVisibility = 0.f;
			visible = !visible;
			SetActorHiddenInGame(visible);
		}
	}
	else
	{
		invincible = false;
		if (visible == true)
		{
			visible = false;
			SetActorHiddenInGame(visible);
		}
	}
}

// Called to bind functionality to input
void APlayerShipNoControlsWithin::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void APlayerShipNoControlsWithin::SetInObstacle(bool inObst)
{
	inObstacle = inObst;
}


void APlayerShipNoControlsWithin::EnteredObstacle()
{
	numObstaclesIn++;
	inObstacle = true;
}

void APlayerShipNoControlsWithin::ExitedObstacle()
{
	if (numObstaclesIn > 0)
	{
		numObstaclesIn--;
		if (numObstaclesIn <= 0)
		{
			inObstacle = false;
		}
	}
}

void APlayerShipNoControlsWithin::Hurt_Simple_Call()
{
	Hurt();
	Hurt_Implementation();
}
void APlayerShipNoControlsWithin::Hurt_Implementation()
{
	if (invincible)
	{
		return;
	}
	currentHP--;
	invincible = true;
	secondsSinceLastShot = 0.f;
	if (currentHP <= 0)
	{
		Die();
		Die_Implementation();
	}
}

void APlayerShipNoControlsWithin::Die_Implementation()
{
	Destroy();
}

bool APlayerShipNoControlsWithin::GetIsInvincible() const
{
	return invincible;
}