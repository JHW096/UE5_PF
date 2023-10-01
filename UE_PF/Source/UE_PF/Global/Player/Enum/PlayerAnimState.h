#pragma once

#include "CoreMinimal.h"
/**
 *
 */
UENUM(BlueprintType)
enum class PlayerAnimState : uint8
{
	NONE,
	IDLE,
	MOVE,
	DASH,
};