// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::aimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO barrel at aimAt UTankAimingComponent"));
		return;
	}

	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

	

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT outLaunchVelocity,
		startLocation,
		hitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if (bHaveAimSolution)
	{
		auto tankName = GetOwner()->GetName();
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aimming at :%s"), *tankName, *aimDirection.ToString());

		MoveBarrel(aimDirection);

		auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim found"), time);
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim found"), time);
	}
		
	

	//auto tankName = GetOwner()->GetName();
	//auto barrelLocation = barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s aimming at :%s from %s"), *tankName, *hitLocation.ToString(), *barrelLocation.ToString());
}

void UTankAimingComponent::MoveBarrel(FVector aimDirection)
{
	auto barrelRotation = barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotation = aimAsRotator - barrelRotation;
	//UE_LOG(LogTemp, Warning, TEXT("aim is rotator :%s"),*deltaRotation.ToString());

	barrel->Elevate(deltaRotation.Pitch);
	turret->Rotate(deltaRotation.Yaw);
}



void UTankAimingComponent::setBarrelReferance(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::setTurretReferance(UTankTurret* turretToSet)
{
	turret = turretToSet;
}

