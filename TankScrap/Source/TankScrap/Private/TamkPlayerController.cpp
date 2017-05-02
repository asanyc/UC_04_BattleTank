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
		//UE_LOG(LogTemp, Error, TEXT("Nothing is under control"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("You are controlling: %s"),*(ControlledTank->GetName()));
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
	// If raycast/linetrace intersects world/landscape
	if (GetSightRayHitLocation(HitLocation)) {
		// turn turret towards intersection point
		GetControlledTank()->AimAt(HitLocation);
	}

}
// Get world location through crosshair
bool ATamkPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find the crosshari screen position
	int32 ViewPortSizeX, ViewPortSizeY = 0;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D(CrossHairXLocaiton * ViewPortSizeX, CrossHairYLocaiton * ViewPortSizeY);
	// UE_LOG(LogTemp, Warning, TEXT("Cursor location: %s"), *ScreenLocation.ToString());

	// Deproject the crosshair from screen- to world-space
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// raycast along that look direction and what we hit
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
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

bool ATamkPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility
		))
	{
		// Set Hit location
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
