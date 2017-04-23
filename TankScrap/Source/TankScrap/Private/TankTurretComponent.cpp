// All mines.

#include "TankScrap.h"
#include "TankTurretComponent.h"

void UTankTurretComponent::Rotate(float RelativeSpeed)
{
	// move it as much as speed allows this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	// Given a max elevation speed and the frame time
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
	// UE_LOG(LogTemp, Warning, TEXT("Barrel Rotate() called %f"), RelativeSpeed);

}


