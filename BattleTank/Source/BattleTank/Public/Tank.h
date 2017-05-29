// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankTrack;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void aimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void setBarrelReferance(UStaticMeshComponent* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTurretReferance(UStaticMeshComponent* turretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTrackReferance(UStaticMeshComponent* trackToSet);

	UFUNCTION(BlueprintCallable, Category = fire)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float launchSpeed = 8000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float reloadTimeInSec = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> projectileBlueprint;



protected:
	UTankAimingComponent* tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UTankBarrel* barrel = nullptr;

	

	double lastFireTime = 0;
};
