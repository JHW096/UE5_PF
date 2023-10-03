// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstanceBase.h"
#include "../Character/Base/PlayerBase.h"

void UPlayerAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	m_AllAnimations = Cast<APlayerBase>(GetOwningActor())->GetAllAnimations();
}

void UPlayerAnimInstanceBase::NativeUpdateAnimation(float _DeltaSecond)
{
	Super::NativeUpdateAnimation(_DeltaSecond);

	if (m_AllAnimations.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) AnimInstance_AllAnimations.Num == 0"), __FUNCTION__, __LINE__);
		return;
	}

	m_AnimState = Cast<APlayerBase>(GetOwningActor())->GetPlayerAnimState();
	m_CurrentMontage = m_AllAnimations[m_AnimState];

	if (m_CurrentMontage == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) AnimInstance_CurrentMontage == nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	if (!Montage_IsPlaying(m_CurrentMontage))
	{
		Montage_Play(m_CurrentMontage, m_AnimSpeed);
	}
}

void UPlayerAnimInstanceBase::PlayIdle()
{
	if (!Montage_IsPlaying(m_AllAnimations[PlayerAnimState::IDLE]))
	{
		m_CurrentMontage = m_AllAnimations[PlayerAnimState::IDLE];
		Montage_Play(m_CurrentMontage, m_AnimSpeed);
	}
	
}

void UPlayerAnimInstanceBase::PlayRun()
{
	if (!Montage_IsPlaying(m_AllAnimations[PlayerAnimState::MOVE]))
	{
		m_CurrentMontage = m_AllAnimations[PlayerAnimState::MOVE];
		Montage_Play(m_CurrentMontage, m_AnimSpeed);
	}
	
}


