// All mines.

#include "TankScrap.h"
#include "TankTracks.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RighttTrackToSet)
{
	if (!LeftTrackToSet || !RighttTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RighttTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move forward throw: %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TOSO prevent compound speed input
}