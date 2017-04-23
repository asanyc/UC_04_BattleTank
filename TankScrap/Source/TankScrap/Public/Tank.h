// All mines.

#pragma once

#include "TankScrap.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declaratikn
class UTankBarrelComponent;
class UTankTurretComponent;
class UTankAimingComponent;

UCLASS()
class TANKSCRAP_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrelComponent* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurretComponent* TurretToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;	// TODO find sensible default
	
};
