// All mines.

#include "Tank.h"
#include "TankScrap.h"
#include "TamkPlayerController.h"


ATank* ATamkPlayerController::GetTankPlayerController() const
{
	return Cast<ATank>(GetPawn());
}

