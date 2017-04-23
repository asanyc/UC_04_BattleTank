// All mines.

#pragma once

#include "TankScrap.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrelComponent;
class UTankTurretComponent;

// Controls Turret and Barrel for aiming.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSCRAP_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrelComponent* BarrelToSet);
	
	void SetTurretReference(UTankTurretComponent* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:	

	UTankBarrelComponent* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UTankTurretComponent* Turret = nullptr;
	void MoveTurretTowards(FVector AimDirection);
};
