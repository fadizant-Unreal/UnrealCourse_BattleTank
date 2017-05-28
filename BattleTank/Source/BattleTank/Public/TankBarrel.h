// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float ReletaveSpeed);
	
	UPROPERTY(EditDefaultsOnly , Category = Setup)
	float maxDegreesPerSec = 10.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxElevationDegrees = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float minElevationDegrees = .0f;
};
