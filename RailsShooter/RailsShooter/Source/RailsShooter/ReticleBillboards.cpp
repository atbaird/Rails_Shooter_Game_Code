// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "ReticleBillboards.h"


// Sets default values
AReticleBillboards::AReticleBillboards()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create Components
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(billboardComponentName);

	//Attatche Components
	BillboardComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	BillboardComponent->SetHiddenInGame(false);
	ToGoOutFrom = nullptr;
	distanceToMaintain = 0.f;
}

// Called when the game starts or when spawned
void AReticleBillboards::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReticleBillboards::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	if (ToGoOutFrom != nullptr)
	{
		FVector loc = ToGoOutFrom->GetActorLocation();
		FVector forward = ToGoOutFrom->GetActorForwardVector() * distanceToMaintain;
		SetActorLocation(loc + forward);
	}
}