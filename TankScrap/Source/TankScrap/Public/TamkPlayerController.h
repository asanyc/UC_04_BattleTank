// All mines.

#pragma once

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
	
public:
	void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	// Starts the tank moving the barrel to where the crosshair inntersects the world
	void AimTowardCrosshair();

};
