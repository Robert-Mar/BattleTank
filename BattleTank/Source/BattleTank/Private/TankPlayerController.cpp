// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerPtr = GetControllerTank();
	if (!ControllerPtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller don't possess a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possess %s"), *(ControllerPtr->GetName()));
	}
}

void ATankPlayerController::Tick( float DeltaTime ) 
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation; //Out parameter 
	if (GetSightRayHitLocation(HitLocation))
	{

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	//Find crosshair location in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *ScreenLocation.ToString());
	return true;
}