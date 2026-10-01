// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeQuestConditionExit.h"
#include "Quest.h"

void UTriggerVolumeQuestConditionExit::StartCondition()
{
	if (!bCompleteOnExit)
	{
		Super::StartCondition();
		return;
	}

	if (AQuest* Quest = Cast<AQuest>(GetOuter()))
	{
		Quest->OnActorEndOverlap.AddDynamic(this, &UTriggerVolumeQuestConditionExit::EndOverlap);
	}
}

void UTriggerVolumeQuestConditionExit::StopCondition()
{
	if (!bCompleteOnExit)
	{
		Super::StopCondition();
		return;
	}

	if (AQuest* Quest = Cast<AQuest>(GetOuter()))
	{
		Quest->OnActorEndOverlap.RemoveDynamic(this, &UTriggerVolumeQuestConditionExit::EndOverlap);
	}
}

void UTriggerVolumeQuestConditionExit::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor->ActorHasTag(OtherTag))
	{
		Complete();
	}
}
