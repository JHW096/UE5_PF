// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordDashNotifyState.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "../../../PlayerController/Base/TopDownMoveController.h"


void UGreatSwordDashNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
}

void UGreatSwordDashNotifyState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	/*CurrentLocation = MeshComp->GetOwner()->GetActorLocation();
	TargetLocation = MeshComp->GetOwner()->GetActorLocation().LeftVector * m_DashDistance;

	FVector vinterp = UKismetMathLibrary::VInterpTo_Constant(CurrentLocation, TargetLocation, FrameDeltaTime, InterpSpeed);

	MeshComp->GetOwner()->SetActorLocation(vinterp);*/
}

void UGreatSwordDashNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
}
