// All mines.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TANKSCRAP_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);
	
};
