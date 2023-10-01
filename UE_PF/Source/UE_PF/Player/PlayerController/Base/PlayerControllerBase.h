// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_PF_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

	virtual void PlayerTick(float _DeltaSeconds) override;

	virtual void SetupInputComponent() override;

public:

	class UInputMappingContext* GetMappingContext() const;
	void SetMappingContext(class UInputMappingContext* _MappingContext);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* m_MappingContext;

	TMap<FName, class UInputAction*> m_InputActionMap;

	UEnhancedInputComponent* m_EnhancedInputComponent;
};
