// Fill out your copyright notice in the Description page of Project Settings.


#include "EmptyQuestCondition.h"

void UEmptyQuestCondition::StartCondition()
{
	// heheheheheehehheehhe
	UE_LOG(LogQuest, Verbose, TEXT("EmptyQuestCondition started (quest %s), it has no logic"), *GetNameSafe(GetOuter()));
}

void UEmptyQuestCondition::StopCondition()
{
	// Колобок повесился
	UE_LOG(LogQuest, Verbose, TEXT("EmptyQuestCondition stopped (quest %s)"), *GetNameSafe(GetOuter()));
}
