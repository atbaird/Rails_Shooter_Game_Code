// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "Obstacle.h"


// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	maxHP = 3;
	currentHP = 3;
	secondsBeforeFlipBackOn = 0.1f;
	secondsBeforeStopBlinking = 0.3f;
	secondsSinceLastFlipped = 0.f;
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	secondsSinceLastHurt = secondsBeforeFlipBackOn;
	invisible = false;
	dead = false;
}

// Called every frame
void AObstacle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (secondsSinceLastHurt < secondsBeforeStopBlinking)
	{
		secondsSinceLastHurt += DeltaTime;
		secondsSinceLastFlipped += DeltaTime;
		if (secondsSinceLastFlipped >= secondsBeforeFlipBackOn)
		{
			secondsSinceLastFlipped = 0.f;
			invisible = !invisible;
		}
	}
	else
	{
		invisible = false;
	}
	SetActorHiddenInGame(invisible);
}

void AObstacle::Damage()
{
	if (canBeHurt == false)
	{
		return;
	}
	currentHP--;
	if (currentHP <= 0)
	{
		dead = true;
	}
	secondsSinceLastHurt = 0.f;
	secondsSinceLastFlipped = 0.f;
}