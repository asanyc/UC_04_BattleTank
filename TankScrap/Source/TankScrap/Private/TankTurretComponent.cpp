// All mines.

#include "TankScrap.h"
#include "TankTurretComponent.h"

void UTankTurretComponent::Rotate(float RelativeSpeed)
{
	// move it as much as speed allows this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	// Given a max elevation speed and the frame time
	auto RotatioChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotatioChange;

	SetRelativeRotation(FRotator(0, FMath::Clamp(RawNewRotation, RotationMinDegrees, RotationMaxDegrees), 0));
	UE_LOG(LogTemp, Warning, TEXT("Barrel Rotate() called %f"), RelativeSpeed);

}


