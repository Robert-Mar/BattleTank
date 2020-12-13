// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/*
 TankeBarrel Component
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories="collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DeltaSeconds);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePersecond = 20;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0;
};
