// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"
#include "QuestSystemComponent.h"
#include "GameFramework/GameModeBase.h"
#include "QuestSettings.h"
#include "QuestCondition.h"

int32 bDebugInstantFinish = 0;
FAutoConsoleVariableRef CVarDebugInstantFinish(TEXT("quest.InstantFinish"),
	bDebugInstantFinish, TEXT("Debug Instantly Finish Quests"),
	ECVF_Cheat);

// Sets default values
AQuest::AQuest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	if (UQuestSystemComponent* QuestComponent = GetWorld()->GetAuthGameMode()->GetComponentByClass<UQuestSystemComponent>())
	{
		QuestComponent->RegisterQuest(this);
	}
	for (const UQuestCondition* ConditionTemplate : QuestSettings->StartConditionsInst)
	{
		if (!ensureMsgf(ConditionTemplate, TEXT("Bad setup for quest %s"), *GetNameSafe(this)))
		{
			UE_LOG(LogQuest, Error, TEXT("Quest %s: empty start condition in settings %s"), *GetNameSafe(this), +*GetNameSafe(QuestSettings));
			return;
		}
		UQuestCondition* QuestCondition = DuplicateObject(ConditionTemplate, this);
		UE_LOG(LogQuest, Log, TEXT("Quest %s: starting start condition %s"), *GetNameSafe(this), +*GetNameSafe(QuestCondition->GetClass()));
		QuestCondition->StartCondition();
		QuestCondition->OnQuestConditionCompleted.AddUObject(this, &AQuest::UpdateStartStatus);
		StartConditions.Add(QuestCondition);
	}
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::UpdateStartStatus()
{
	for (UQuestCondition* Condition : StartConditions)
	{
		if (!ensure(Condition))
		{
			UE_LOG(LogQuest, Error, TEXT("Quest %s: null start condition"), *GetNameSafe(this));
			return;
		}
		if (!Condition->IsCompleted())
		{
			UE_LOG(LogQuest, Verbose, TEXT("Quest %s: start condition %s is not completed yet"), *GetNameSafe(this), +*GetNameSafe(Condition->GetClass()));
			return;
		}
	}

	QuestStatus = EQuestStatus::Started;

	if (bDebugInstantFinish)
	{
		QuestStatus = EQuestStatus::Completed;
		return;
	}

	for (const UQuestCondition* ConditionTemplate : QuestSettings->EndConditionsInst)
	{
		if (!ensureMsgf(ConditionTemplate, TEXT("Bad setup for quest %s"), *GetNameSafe(this)))
		{
			UE_LOG(LogQuest, Error, TEXT("Quest %s: empty end condition in settings %s"), *GetNameSafe(this), +*GetNameSafe(QuestSettings));
			return;
		}
		UQuestCondition* QuestCondition = DuplicateObject(ConditionTemplate, this);
		UE_LOG(LogQuest, Log, TEXT("Quest %s: starting end condition %s"), *GetNameSafe(this), +*GetNameSafe(QuestCondition->GetClass()));
		QuestCondition->StartCondition();
		QuestCondition->OnQuestConditionCompleted.AddUObject(this, &AQuest::UpdateEndStatus);
		EndConditions.Add(QuestCondition);
	}

}

void AQuest::UpdateEndStatus()
{
	for (UQuestCondition* Condition : StartConditions)
	{
		if (ensure(Condition))
		{
			return;
		}
		if (!Condition->IsCompleted())
		{
			return;
		}
	}
	UE_LOG(LogQuest, Log, TEXT("All conditions completed"));
	QuestStatus = EQuestStatus::Completed;
}

