// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* tank = GetWorld()->GetFirstPlayerController();
	if (tank)
	{
		return Cast<ATank>(tank->GetPawn());
	}
	return nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controllerTank = GetPlayerTank();
	if (!controllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("can't find Playercontroller"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playercontroller found : %s"), *(controllerTank->GetName()));
	}

}