// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "../../Global/Player/Enum/PlayerAnimState.h"
#include "PlayerAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_PF_API UPlayerAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
	
protected:

	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float _DeltaSecond) override;

public:

	UFUNCTION()
	virtual void MontageBlendOut(UAnimMontage* _Anim, bool _Inter);

	void PlayIdle();
	void PlayRun();

protected:
	
	TMap<PlayerAnimState, UAnimMontage*> m_AllAnimations;

	UAnimMontage* m_CurrentMontage = nullptr;

	PlayerAnimState m_AnimState;

	float m_AnimSpeed = 1.0f;
};
