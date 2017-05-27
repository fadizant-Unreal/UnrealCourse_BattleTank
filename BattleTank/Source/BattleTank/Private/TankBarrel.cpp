// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float ReletaveSpeed)
{
	ReletaveSpeed = FMath::Clamp<float>(ReletaveSpeed, -1, +1);
	auto elevationChange = ReletaveSpeed * maxDegreesPerSec * GetWorld()->DeltaTimeSeconds;
	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
	auto elevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);

	SetRelativeRotation(FRotator(elevation, 0, 0));
}
