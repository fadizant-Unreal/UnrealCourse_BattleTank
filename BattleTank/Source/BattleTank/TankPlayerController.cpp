// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto controllerTank = GetControlledTank();
	if (!controllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller not connect"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller connected : %s"), *(controllerTank->GetName()));
	}
	
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimToCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Playercontroller Tick"));
}

void ATankPlayerController::AimToCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(OUT HitLocation))
	{
	}

	//UE_LOG(LogTemp, Warning, TEXT("Look direction :%s"), *HitLocation.ToString());

	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & hitLocation) const
{
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(OUT viewPortSizeX, OUT viewPortSizeY);

	FVector2D Screenlocation = FVector2D(viewPortSizeX*crossHairXLocation, viewPortSizeY*crossHairYLocation);

	FVector lookDirection;
	if (GetLookDirection(Screenlocation, OUT lookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction :%s"), *lookDirection.ToString());
	}
	//hitLocation = FVector(Screenlocation, .0f);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D Screenlocation , FVector &lookDirection) const
{
	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(Screenlocation.X, Screenlocation.Y, OUT cameraWorldLocation, OUT lookDirection);
}
