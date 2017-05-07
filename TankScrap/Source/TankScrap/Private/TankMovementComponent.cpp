// All mines.

#include "TankScrap.h"
#include "TankMovementComponent.h"




void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move forward throw: %f"), Throw);

}