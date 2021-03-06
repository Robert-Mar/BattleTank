// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControllerTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerPawn = GetPlayerTank();
	//auto PlayerPawn = GetControllerTank();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller don't possess Tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesses %s."), *(PlayerPawn->GetName()));
	}
}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

