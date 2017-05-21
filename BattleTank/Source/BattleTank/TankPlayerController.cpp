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