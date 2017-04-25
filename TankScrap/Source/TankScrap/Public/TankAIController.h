// All mines.

#pragma once

#include "TankScrap.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class Atank;	// Forward Declaration
/**
 * 
 */
UCLASS()
class TANKSCRAP_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void ATankAIController::Tick(float DeltaTime) override;
};
