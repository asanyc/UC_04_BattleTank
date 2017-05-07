// All mines.

#include "TankScrap.h"
#include "TankTracks.h"


void UTankTracks::SetThrottle(float throttle)
{

	// TODO clamp throttle inputs so player can't overdrive
	auto ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

