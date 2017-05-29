// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTrack.h"
#include "Tank.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::aimAt(FVector hitLocation)
{
	tankAimingComponent->aimAt(hitLocation, launchSpeed);
}

void ATank::setBarrelReferance(UStaticMeshComponent* barrelToSet)
{
	tankAimingComponent->setBarrelReferance((UTankBarrel*)barrelToSet);
	barrel = (UTankBarrel*)barrelToSet;
}

void ATank::setTurretReferance(UStaticMeshComponent* turretToSet)
{
	tankAimingComponent->setTurretReferance((UTankTurret*)turretToSet);
}

void ATank::setTrackReferance(UStaticMeshComponent* trackToSet)
{
	tankAimingComponent->setTrackReferance((UTankTrack*)trackToSet);
}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Fire"));

	bool isReload = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSec;

	if (barrel && isReload)
	{
		FVector projectileLocation = barrel->GetSocketLocation(FName("Projectile"));
		FRotator projectileRotation = barrel->GetSocketRotation(FName("Projectile"));

		UE_LOG(LogTemp, Warning, TEXT("Hit location :%s"), *projectileLocation.ToString());

		auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBlueprint, projectileLocation, projectileRotation);

		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}

	
}

