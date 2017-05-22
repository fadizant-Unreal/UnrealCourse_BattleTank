// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controllerTank = GetControlledTank();
	if (!controllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not connect"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController connected : %s"), *(controllerTank->GetName()));
	}

}