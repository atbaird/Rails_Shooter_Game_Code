// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "Checkpoint.h"
#include "Cameras/EmptyRailsCamera.h"


// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	active = false;
	relPositionSet = false;
	//Create Components
	CheckpointMesh = CreateDefaultSubobject<UStaticMeshComponent>(meshComponentName);
	RootComponent = CreateDefaultSubobject<USceneComponent>(rootComponentName);
	sphereActivationCollision = CreateDefaultSubobject<USphereComponent>(sphereActivationCollisionComponentName);

	//Attach components to each other
	CheckpointMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	sphereActivationCollision->SetupAttachment(RootComponent);

	DistanceBackFromRelForwardToMaintain = 0.f;

	//SphereCollision Setup.
	sphereActivationCollision->InitSphereRadius(250.0f);
	sphereActivationCollision->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlapBegin);       // set up a notification for when this component overlaps something
	sphereActivationCollision->OnComponentEndOverlap.AddDynamic(this, &ACheckpoint::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();

	relPositionSet = false;
	RecalRelativeCameraPosition();
}

// Called every frame
void ACheckpoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (relPositionSet == false)
	{
		RecalRelativeCameraPosition();
	}
}

void ACheckpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TSubclassOf<ACheckpoint> ClassToFind;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		ACheckpoint* checkPoint = Cast<ACheckpoint>(FoundActors[i]);
		checkPoint->SetActive(false);
	}
	this->SetActive(true);
}

/** called when something leaves sphereCollision */
void ACheckpoint::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{

}

void ACheckpoint::SetActive(bool act)
{
	active = act;
}

void ACheckpoint::RecalRelativeCameraPosition()
{

	TSubclassOf<AEmptyRailsCamera> ClassToFind;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	if (FoundActors.Num() == 0)
	{
		return;
	}
	AEmptyRailsCamera* cam = Cast<AEmptyRailsCamera>(FoundActors[0]);
	FVector myPosition = GetActorLocation();
	FVector camForward = cam->GetActorForwardVector();
	FVector camPosition = cam->GetActorLocation();
	FVector positionDiff = myPosition - camPosition;

	//Do the projection of the distance between this and the Camera upon the camera's forward
	//This is so as we get relatively how far forwards from the camera position to set our relative respawn position.
	//Reason we want this is so we can put the camera in the correct spot when we respawn.
	FVector distanceForwardToGo = ((camForward * positionDiff) / (positionDiff * positionDiff)) * positionDiff;
	RelativeCameraPosition = camPosition + distanceForwardToGo - (DistanceBackFromRelForwardToMaintain * camForward);
	relPositionSet = true;
	
}