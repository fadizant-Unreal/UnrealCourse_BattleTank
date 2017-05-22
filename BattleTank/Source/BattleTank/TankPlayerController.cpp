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

	UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());

	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & hitLocation) const
{
	hitLocation = FVector(1.0);
	return false;
}