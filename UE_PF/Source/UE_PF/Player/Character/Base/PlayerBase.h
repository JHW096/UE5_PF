// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
	class UCameraComponent* SetCameraComponent(class UCameraComponent* _CameraComponent);

private:
	//CameraComponent

	//UPROPERTY(Category = "SpringArmComponent", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* m_SpringArmComponent; 
	
	class UCameraComponent* m_CameraComponent;


};
