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
	void Elevate(float DegreesPerSec);
	
	UPROPERTY(EditAnywhere , Category = Setup)
	float maxDegreesPerSec = 20.0f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevationDegrees = 40.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevationDegrees = .0f;
};
