// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownMoveController.h"
#include "TopDownMoveController.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>

ATopDownMoveController::ATopDownMoveController()
{
	bShowMouseCursor = true;
	m_CachedDestination = FVector::ZeroVector;
}

void ATopDownMoveController::BeginPlay()
{
	Super::BeginPlay();
}

void ATopDownMoveController::PlayerTick(float _DeltaSeconds)
{
	Super::PlayerTick(_DeltaSeconds);
}

void ATopDownMoveController::SetupInputComponent()
{
	Super::SetupInputComponent();

	{
		m_EnhancedInputComponent->BindAction(
			InputMouseRAction, ETriggerEvent::Started, this, &ATopDownMoveController::OnInputMouseRStarted
		);
		m_EnhancedInputComponent->BindAction(
			InputMouseRAction, ETriggerEvent::Triggered, this, &ATopDownMoveController::OnSetDestinationTriggered
		);
		m_EnhancedInputComponent->BindAction(
			InputMouseRAction, ETriggerEvent::Completed, this, &ATopDownMoveController::OnSetDestinationReleased
		);
		m_EnhancedInputComponent->BindAction(
			InputMouseRAction, ETriggerEvent::Canceled, this, &ATopDownMoveController::OnSetDestinationReleased
		);
	}
}


void ATopDownMoveController::OnInputMouseRStarted()
{
}

void ATopDownMoveController::OnSetDestinationTriggered()
{
	FollowTime += GetWorld()->GetDeltaSeconds();

	if (HitSucceeded())
	{
		SetCacheDestination(m_CursorHitResult.Location);
	}

	APawn* PlayerPawn = GetPawn();
	//GetPawn nullptr check
	if (PlayerPawn != nullptr)
	{
		//Prev Way to Move
		//WorldDirection = FVector(Hit Location, MainPlayer Location) NormalVector
		//ControlledPawn->AddMovementInput(WorldDirection, 1.0f, false);
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, m_CachedDestination);
	}
}

void ATopDownMoveController::OnSetDestinationReleased()
{
	FollowTime = 0.0f;
}

void ATopDownMoveController::OnInputSpaceStarted()
{
}

bool ATopDownMoveController::HitSucceeded()
{
	return GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, m_CursorHitResult) == true ? true : false;
}
