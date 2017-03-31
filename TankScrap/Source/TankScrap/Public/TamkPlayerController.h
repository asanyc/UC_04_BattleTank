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
	ATank* GetTankPlayerController() const;
	
	
};
