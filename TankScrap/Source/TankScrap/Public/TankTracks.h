// All mines.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKSCRAP_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttle between -1.0 and +1.0
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000;	// Assume a 40 ton Tank, and 1g
	
	
	
	
};
