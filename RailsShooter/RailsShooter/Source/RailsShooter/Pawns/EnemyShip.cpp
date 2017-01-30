// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "EnemyShip.h"
#include "../Pawns/PlayerShipNoControlsWithin.h"


// Sets default values
AEnemyShip::AEnemyShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	constantlyMoveForwardIfUnpaused = true;
	paused = true;
	secondsPassedWhileUnpaused = 0.f;
	movementSpeed = 200.f;
	loopShootingPattern = false;
	additionalDelayAfterFirstFiringLoop = 1.f;
	maxHP = 1;
	secondsBeforeStopInvincilityFrames = 0.5f;
	secondsBeforeSwitchVisibility = 0.1f;
	numObstaclesIn = 0;
	lookAtTarget = false;
	nearestTarget = nullptr;
	targetLookAtRadius = 1000.f;
}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();
	numObstaclesIn = 0;
	CopyFireTimers();
	rotationToTurnTowards = GetActorRotation();
	if (maxHP <= 0)
	{
		maxHP = 1;
	}
	currentHP = maxHP;
	secondsSinceLastShot = secondsBeforeStopInvincilityFrames;
	secondsSinceLastFlippedVisibility = 0.f;
	visible = true;
	originalRotation = GetActorRotation();
}

// Called every frame
void AEnemyShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (paused == false)
	{
		secondsPassedWhileUnpaused += DeltaTime;
		if (secondsSinceLastShot < secondsBeforeStopInvincilityFrames)
		{
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
			if (visible == true)
			{
				visible = false;
				SetActorHiddenInGame(visible);
			}
		}

		FindNearestValidTarget();
		RotationUpdate(DeltaTime);
		MoveForwardUpdate(DeltaTime);
		FireUpdate(DeltaTime);
	}
}

// Called to bind functionality to input
void AEnemyShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AEnemyShip::Fire_Implementation()
{

}

void AEnemyShip::FindNearestValidTarget()
{
	TSubclassOf<APlayerShipNoControlsWithin> ClassToFind;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	AActor* nearestSoFar = nullptr;
	float nearestDistance = 0.f;
	bool foundOne = false;
	for (TActorIterator<APlayerShipNoControlsWithin> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		APlayerShipNoControlsWithin* current = *ActorItr;
		if (current != nullptr)
		{
			FVector difference = GetActorLocation() - current->GetActorLocation();
			float length = FMath::Abs(difference.Size());
			UE_LOG(LogTemp, Warning, TEXT("%f"), length);
			if (length <= targetLookAtRadius && (foundOne == false || (length < nearestDistance)))
			{
				nearestDistance = length;
				foundOne = true;
				nearestSoFar = current;
			}
		}
	}
	//targetLookAtRadius
	nearestTarget = nearestSoFar;
}

void AEnemyShip::RotationUpdate(float DeltaSeconds)
{
	if (lookAtTarget == false)
	{
		float highestTimeHit = -9999999999999999999999.f;
		bool changed = false;
		for (size_t i = 0; i < secondsBeforeTurn.Num() && i < rotationToTake.Num(); i++)
		{
			float previousTime = secondsBeforeTurn[i];
			secondsBeforeTurn[i] -= DeltaSeconds;
			if (previousTime > 0.f && secondsBeforeTurn[i] <= 0.f)
			{
				if (secondsBeforeTurn[i] > highestTimeHit)
				{
					rotationToTurnTowards = rotationToTake[i];
					changed = true;
				}
			}
		}
		//if (changed)
		{
			SetActorRotation(FMath::Lerp(GetActorRotation(), rotationToTurnTowards, 0.05f));
		}
	}
	else
	{
		if (nearestTarget != nullptr)
		{
			FVector difference = nearestTarget->GetActorLocation() - this->GetActorLocation();
			difference.Normalize();
			rotationToTurnTowards = FRotationMatrix::MakeFromX(difference).Rotator();
			SetActorRotation(FMath::Lerp(GetActorRotation(), rotationToTurnTowards, 0.05f));
		}
		else
		{
			SetActorRotation(FMath::Lerp(GetActorRotation(), originalRotation, 0.05f));
		}
	}
}

void AEnemyShip::MoveForwardUpdate(float DeltaSeconds)
{
	if (constantlyMoveForwardIfUnpaused)
	{
		FVector forward = GetActorForwardVector() * DeltaSeconds * movementSpeed;
		SetActorLocation(GetActorLocation() + forward);
	}
}

void AEnemyShip::FireUpdate(float DeltaSeconds)
{
	if (lookAtTarget == true && nearestTarget == nullptr)
	{
		return;
	}
	float highestShootValue = -999999999999.f;
	for (size_t i = 0; i < fired.Num(); i++)
	{
		float currentSeconds = secondsBeforeFireWhileUnpaused[i];
		if (currentSeconds > highestShootValue)
		{
			highestShootValue = currentSeconds;
		}
		if (fired[i] == true)
		{
			continue;
		}

		{
			secondsBeforeFireWhileUnpaused[i] -= DeltaSeconds;
			if (secondsBeforeFireWhileUnpaused[i] <= 0.f)
			{
				fired[i] = true;
				Fire();
			}
		}
	}
	if (highestShootValue <= 0.f && loopShootingPattern)
	{
		CopyFireTimers();
	}
}

void AEnemyShip::Unpause_Implementation()
{
	paused = false;
}

void AEnemyShip::Pause_Implementation()
{
	paused = false;
}

void AEnemyShip::SetInObstacle(bool inObs)
{
	inObstacle = inObs;
}


void AEnemyShip::EnteredObstacle()
{
	numObstaclesIn++;
	inObstacle = true;
}

void AEnemyShip::ExitedObstacle()
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

void AEnemyShip::Hurt_Simple_Call()
{
	Hurt();
	Hurt_Implementation();
}

void AEnemyShip::Hurt_Implementation()
{
	currentHP--;
	secondsSinceLastShot = 0.f;
	if (currentHP <= 0)
	{
		Die();
		Die_Implementation();
	}
}

void AEnemyShip::Die_Implementation()
{
	if (currentHP > 0)
	{
		return;
	}

	Destroy();
}


void AEnemyShip::CopyFireTimers()
{
	float delay = 0.f;
	if (setUpOnce)
	{
		delay = additionalDelayAfterFirstFiringLoop;
	}
	else
	{
		setUpOnce = true;
	}
	if (secondsBeforeFireWhileUnpaused.Num() != secondsBeforeFireWhileUnpausedLoop.Num())
	{
		secondsBeforeFireWhileUnpaused.SetNum(secondsBeforeFireWhileUnpausedLoop.Num());
	}
	if (fired.Num() != secondsBeforeFireWhileUnpaused.Num())
	{
		fired.SetNum(secondsBeforeFireWhileUnpaused.Num());
	}
	for (size_t i = 0; i < fired.Num(); i++)
	{
		fired[i] = false;
		secondsBeforeFireWhileUnpaused[i] = secondsBeforeFireWhileUnpausedLoop[i] + delay;
	}
}