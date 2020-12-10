// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last line to include 

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank * GetControllerTank() const;
	
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);
public:
	UPROPERTY( EditAnywhere )
	float CrosshairXLocation = 0.5;

	UPROPERTY( EditAnywhere )
	float CrosshairYLocation = 0.33333;
};
