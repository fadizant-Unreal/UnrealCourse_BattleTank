// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"




void UTankTrack::setThrottle(float throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s throttle :%f"), *GetName(), throttle);

	auto foceApplied = GetForwardVector() * throttle * TrackMacDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(foceApplied, forceLocation);
}
