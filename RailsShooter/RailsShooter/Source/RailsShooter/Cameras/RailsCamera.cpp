// Fill out your copyright notice in the Description page of Project Settings.

#include "RailsShooter.h"
#include "RailsCamera.h"



// Sets default values
ARailsCamera::ARailsCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	OurCamera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ARailsCamera::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* controller1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APlayerController* controller2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	if (controller1 != nullptr)
	{
		controller1->SetViewTarget(this);
	}
	if (controller2 != nullptr)
	{
		controller2->SetViewTarget(this);
	}
}

// Called every frame
void ARailsCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector loc = GetActorLocation();
	FVector forward = GetActorForwardVector();
	SetActorLocation(loc + (forward * MovementSpeedMultiplier));
}

float ARailsCamera::GetCameraOrthoWidth_Implementation()
{
	if (GEngine)
	{
		return GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetOrthoWidth();
	}
	return 0.f;
}
float ARailsCamera::GetCameraOrthoHeight_Implementation()
{
	if (GEngine)
	{
		return GetCameraOrthoWidth_Implementation() / GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->DefaultAspectRatio;
	}
	return 0.f;
}