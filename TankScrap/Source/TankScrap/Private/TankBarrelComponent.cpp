// All mines.

#include "TankScrap.h"
#include "TankBarrelComponent.h"


void UTankBarrelComponent::Elevate(float DegreesPerSecond)
{
	// move it as much as speed allows this frame
	// Given a max elevation speed and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate() called %f"), DegreesPerSecond);

}