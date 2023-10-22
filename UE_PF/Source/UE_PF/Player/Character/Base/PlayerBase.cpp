// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"



// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	{
		PrimaryActorTick.bCanEverTick = true;
		PrimaryActorTick.bStartWithTickEnabled = true;
	}

	//PLAYER_ROTATION_SET
	{
		bUseControllerRotationPitch = false;
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false;
	}

	//PLAYER_MOVEMENT_SET
	{
		//PLAYER_ROTATE_RATE_SET_
		GetCharacterMovement()->bOrientRotationToMovement = true;

		//PLAYER_ROTATION_RATE_FOR_SECONDS
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);

		//PLAYER_CAN_BE_START_PLANE
		GetCharacterMovement()->bConstrainToPlane = true;
		GetCharacterMovement()->bSnapToPlaneAtStart = true;
	}

	//SPRINGARM_COMPONENT
	{
		//CreateObject
		m_SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARMCOMPONENT"));
		//Root(Capsule)Attach
		m_SpringArmComponent->SetupAttachment(RootComponent);
		//Fix_To_Arm_Rotation
		m_SpringArmComponent->SetUsingAbsoluteRotation(true);
		//Length_To_Player_And_Camera
		m_SpringArmComponent->TargetArmLength = 1250.0f;
		m_SpringArmComponent->SetRelativeRotation(FRotator(-50.0f, 0.0f, 0.0f));
		//CameraCollisionTest_Off
		m_SpringArmComponent->bDoCollisionTest = false;
	}

	//CAMERACOMPONENT
	{
		m_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("MAINCAMERACOMPONENT"));
		m_CameraComponent->SetupAttachment(m_SpringArmComponent);
		//Fix_Rotation
		m_CameraComponent->bUsePawnControlRotation = false; 
	}


	//ADD_ACTORCOMPOENENT
	{
		//TODO_
	}

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveAction();

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UCameraComponent* APlayerBase::GetCameraComponent()
{
	return m_CameraComponent;
}

void APlayerBase::SetCameraComponent(UCameraComponent* _CameraComponent)
{
	m_CameraComponent = _CameraComponent;
}

void APlayerBase::MoveAction()
{
	/*if (GetPlayerIsAttacking())
	{
		return;
	}*/

	if (m_AnimState == PlayerAnimState::DASH)
	{
		return;
	}

	m_AnimState = GetVelocity().Size() > 1.0f ? PlayerAnimState::MOVE : PlayerAnimState::IDLE;
}

TMap<PlayerAnimState, UAnimMontage*> APlayerBase::GetAllAnimations()
{
	return m_AllAnimations;
}

PlayerAnimState APlayerBase::GetPlayerAnimState()
{
	return m_AnimState;
}

void APlayerBase::SetPlayerAnimState(PlayerAnimState _PlayerAnimState)
{
	m_AnimState = _PlayerAnimState;
}

bool APlayerBase::GetPlayerIsAttacking()
{
	
	switch (m_AnimState)
	{
		case PlayerAnimState::NONE:
		case PlayerAnimState::IDLE:
		case PlayerAnimState::MOVE:
		case PlayerAnimState::DASH:
		{
			return false;
		}
			break;
		default:
			break;
	}

	return true;
}

void APlayerBase::SetPlayerIsAttacking(bool _IsAttacking)
{
	m_IsAttacking = _IsAttacking;
}
