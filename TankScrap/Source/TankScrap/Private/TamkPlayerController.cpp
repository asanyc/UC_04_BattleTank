// All mines.

#include "TankScrap.h"
#include "Tank.h"
#include "TamkPlayerController.h"

void ATamkPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		// UE_LOG(LogTemp, Error, TEXT("Player Controller Ticking"));
		AimTowardCrosshair();

}

void ATamkPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Nothing is under control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You are controlling: %s"),*(ControlledTank->GetName()));
	}
	
}

ATank* ATamkPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATamkPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location through crosshair
	// If raycast/linetrace intersects world/landscape
		// turn turret towards intersection point

}
