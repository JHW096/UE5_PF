// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerBase.h"
#include "TopDownMoveController.generated.h"

/**
 * 
 */
UCLASS()
class UE_PF_API ATopDownMoveController : public APlayerControllerBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InputMouseRAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InputSpaceAction;

protected:

	ATopDownMoveController();

	virtual void BeginPlay() override;

	virtual void PlayerTick(float _DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	//void MoveAction();

public:

	void OnInputMouseRStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();

	void OnInputSpaceStarted();

public:

	bool HitSucceeded();

	FORCEINLINE FHitResult GetCursorHitResult() const
	{
		return m_CursorHitResult;
	}

	FORCEINLINE FVector GetCachedDestination() const
	{
		return m_CachedDestination;
	}

	FORCEINLINE void SetCacheDestination(FVector _CachedDestination)
	{
		m_CachedDestination = _CachedDestination;
	}


private:

	FHitResult m_CursorHitResult;
	FVector m_CachedDestination;
	float FollowTime;
};
