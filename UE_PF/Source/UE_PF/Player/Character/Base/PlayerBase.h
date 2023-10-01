// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../../../Global/Player/Enum/PlayerAnimState.h"
#include "PlayerBase.generated.h"

UCLASS()
class UE_PF_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	class UCameraComponent* GetCameraComponent();
	void SetCameraComponent(class UCameraComponent* _CameraComponent);

public:

	void MoveAction();

	void SetPlayerAnimState(PlayerAnimState _PlayerAnimState);

	bool GetPlayerIsAttacking();
	
	void SetPlayerIsAttacking(bool _IsAttacking);

protected:

	UPROPERTY(Category = "Animation_Value", EditAnywhere, BlueprintReadWrite)
	PlayerAnimState m_AnimState;

	bool m_IsAttacking = false;

	UPROPERTY(Category = "Animation_Value", EditAnywhere, BlueprintReadWrite)
	TMap<PlayerAnimState, UAnimMontage*> m_AllAnimations;
	
private:
	//CameraComponent

	//UPROPERTY(Category = "SpringArmComponent", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* m_SpringArmComponent; 
	
	class UCameraComponent* m_CameraComponent;

private:

	const int32 PLAYER_SKILL_NUM = 4;
};
