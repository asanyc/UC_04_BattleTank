// All mines.

#include "TankScrap.h"
#include "TankBarrelComponent.h"


void UTankBarrelComponent::Elevate(float RelativeSpeed)
{
	// move it as much as speed allows this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	// Given a max elevation speed and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, ElevationMinDegrees, ElevationMaxDegrees), 0, 0));
	//UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate() called %f"), RelativeSpeed);

}