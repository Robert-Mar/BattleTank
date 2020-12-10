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
	//UE_LOG(LogTemp, Warning, TEXT("The Player Controller is Ticking"));
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{

}
