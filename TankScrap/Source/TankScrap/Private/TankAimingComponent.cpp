// All mines.

#include "TankScrap.h"
#include "TankTurretComponent.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	// TODO shoudl this tick?

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel || !Turret) { return; }

	FVector OutTossVelocity;
	FVector MuzzleLocation = Barrel->GetSocketLocation(FName("Muzzle"));
	//calculate launch vector
	bool IsAimingVector = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutTossVelocity,
		MuzzleLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	auto Time = GetWorld()->GetTimeSeconds();

	if (IsAimingVector)
	{
		auto AimDirection = OutTossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
		// UE_LOG(LogTemp, Warning, TEXT("%f: aim solution @ %s"), Time, *AimDirection.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solution found"), Time);
	}


}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work out the difference between the barels curent rotation and the desired aimdirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	// Work out the difference between the barels curent rotation and the desired aimdirection
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->Rotate(DeltaRotator.Yaw);
}


// Setup barrel reference for aiming
void UTankAimingComponent::SetBarrelReference(UTankBarrelComponent* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

// Setup Turret reference for aiming
void UTankAimingComponent::SetTurretReference(UTankTurretComponent* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}