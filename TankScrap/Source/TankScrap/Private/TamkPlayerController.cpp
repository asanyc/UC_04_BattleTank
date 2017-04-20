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

	FVector HitLocation;  // out parameter for raycast
	if (GetSightRayHitLocation(HitLocation)) {
		// UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		// If raycast/linetrace intersects world/landscape
		// turn turret towards intersection point
	}

}
// Get world location through crosshair
bool ATamkPlayerController::GetSightRayHitLocation(FVector& hit) const
{
	// find the crosshari screen position
	int32 ViewPortSizeX, ViewPortSizeY = 0;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D(CrossHairXLocaiton * ViewPortSizeX, CrossHairYLocaiton * ViewPortSizeY);
	// UE_LOG(LogTemp, Warning, TEXT("Cursor location: %s"), *ScreenLocation.ToString());
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Aim Direction: %s"), *LookDirection.ToString());
	}
	// Deproject the crosshair from screen- to world-space
	// raycast along that look direction and what we hit
	hit = FVector(1.0);
	return true;
}

bool ATamkPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}