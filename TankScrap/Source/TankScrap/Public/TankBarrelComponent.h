// All mines.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrelComponent.generated.h"

/**
 * 
 */

// Contains Barrel aiming elevation and speed
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision","Lighting","Rendering","Component Replication","Cooking","Mobile"))
class TANKSCRAP_API UTankBarrelComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	// Speed of elevation during aiming
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5;

	// How far down can the barrel pitch from level?  Can go lower in from, but this is the rear safety declination
	UPROPERTY(EditAnywhere, Category = Setup)
	float ElevationMinDegrees = 0;	

	// How far the barrel can rise during aiming & target acquisition
	UPROPERTY(EditAnywhere, Category = Setup)
	float ElevationMaxDegrees = 40;	

};
