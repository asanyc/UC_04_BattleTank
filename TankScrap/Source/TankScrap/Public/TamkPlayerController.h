// All mines.

#pragma once

#include "TankScrap.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TamkPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKSCRAP_API ATamkPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	// Starts the tank moving the barrel to where the crosshair inntersects the world
	void AimTowardCrosshair();

	bool ATamkPlayerController::GetSightRayHitLocation(FVector& hit) const;
	bool ATamkPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool ATamkPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocaiton = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocaiton = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;


};
