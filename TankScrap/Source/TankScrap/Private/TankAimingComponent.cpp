// All mines.

#include "TankScrap.h"
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
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutTossVelocity,
		MuzzleLocation,
		HitLocation,
		LaunchSpeed,
		false,
		6.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace)
		)
	{
		auto AimDirection = OutTossVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("Firing at %s"), *AimDirection.ToString());
	}


}

// Setup barrel reference for aiming
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
