// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float ReletaveSpeed)
{
	ReletaveSpeed = FMath::Clamp<float>(ReletaveSpeed, -1, +1);
	auto rotationChange = ReletaveSpeed * maxDegreesPerSec * GetWorld()->DeltaTimeSeconds;
	auto rotation = RelativeRotation.Yaw + rotationChange;

	SetRelativeRotation(FRotator(0, rotation, 0));
}


