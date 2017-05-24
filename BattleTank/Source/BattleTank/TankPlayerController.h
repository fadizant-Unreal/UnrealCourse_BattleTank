// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float crossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float crossHairYLocation = 0.33333f;

private:
	void AimToCrosshair();
	bool GetSightRayHitLocation(FVector & hitLocation) const;
	bool GetLookDirection(FVector2D Screenlocation, FVector &lookDirection) const;
};
