// All mines.

#pragma once

#include "TankScrap.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrelComponent;	

// Controls Turret and Barrel for aiming.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSCRAP_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrelComponent* BarrelToSet);

	// TODO add void SetTurretReference(UStaticMeshComponent* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);


private:	
	UTankBarrelComponent* Barrel = nullptr;
		
	void MoveBarrelTowards(FVector AimDirection);
};
