// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "EnhancedInputSubsystems.h"

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(m_MappingContext, 0);
	}
}

void APlayerControllerBase::PlayerTick(float _DeltaSeconds)
{
	Super::PlayerTick(_DeltaSeconds);
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	m_EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	if (!m_EnhancedInputComponent)
	{
		return;
	}
}

UInputMappingContext* APlayerControllerBase::GetMappingContext() const
{
	if (m_MappingContext == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) MappingContext == nullptr"), __FUNCTION__, __LINE__);
		return nullptr;
	}
	return m_MappingContext;
}

void APlayerControllerBase::SetMappingContext(UInputMappingContext* _MappingContext)
{
	if (m_MappingContext == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s(%u) MappingContext == nullptr"), __FUNCTION__, __LINE__);
		return;
	}
	m_MappingContext = _MappingContext;
}
