// All mines.

#include "TankScrap.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

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
		6.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (IsAimingVector)
	{
		auto AimDirection = OutTossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		// UE_LOG(LogTemp, Warning, TEXT("Firing at %s"), *AimDirection.ToString());
	}


}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work out the difference between the barels curent rotation and the desired aimdirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5);	// TODO remove magic number
}


// Setup barrel reference for aiming
void UTankAimingComponent::SetBarrelReference(UTankBarrelComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

