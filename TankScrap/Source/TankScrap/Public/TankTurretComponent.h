// All mines.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurretComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision", "Lighting", "Rendering", "Component Replication", "Cooking", "Mobile"))
class TANKSCRAP_API UTankTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	// Speed of rotation during aiming
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5;

	// How far the barrel can turn right during aiming & target acquisition
	UPROPERTY(EditAnywhere, Category = Setup)
		float RotationMinDegrees = 0;

	// How far the barrel can turn left during aiming & target acquisition
	UPROPERTY(EditAnywhere, Category = Setup)
		float RotationMaxDegrees = 40;

	
	
};
