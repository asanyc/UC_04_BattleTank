// All mines.

#include "TankScrap.h"
#include "TankTracks.h"


void UTankTracks::SetThrottle(float throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s set Throttle to %f"), *Name, throttle);

	// TODO clamp throttle inputs so player can't overdrive
	auto ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

