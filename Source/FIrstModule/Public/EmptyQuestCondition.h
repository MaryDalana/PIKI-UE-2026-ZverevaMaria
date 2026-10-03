// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestCondition.h"
#include "EmptyQuestCondition.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class FIRSTMODULE_API UEmptyQuestCondition : public UQuestCondition
{
	GENERATED_BODY()

public:
	virtual void StartCondition() override;
	virtual void StopCondition() override;
};
