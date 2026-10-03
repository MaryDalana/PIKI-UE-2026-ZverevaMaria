// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TriggerVolume_QuestCondition.h"
#include "TriggerVolumeQuestConditionExit.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class FIRSTMODULE_API UTriggerVolumeQuestConditionExit : public UTriggerVolume_QuestCondition
{
	GENERATED_BODY()

public:
	virtual void StartCondition() override;
	virtual void StopCondition() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCompleteOnExit = false;

	UFUNCTION()
	void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
