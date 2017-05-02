// All mines.

#include "TankScrap.h"
#include "TankTracks.h"


void UTankTracks::SetThrottle(float throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s set Throttle to %f"), *Name, throttle);
}

