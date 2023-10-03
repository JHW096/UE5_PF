// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAnimInstanceBase.h"
#include "GreatSwordAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class UE_PF_API UGreatSwordAnimInst : public UPlayerAnimInstanceBase
{
	GENERATED_BODY()
	
protected:

	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float _DeltaSecond) override;

public:


};
