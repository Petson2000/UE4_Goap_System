// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "G_SubGoal.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct FGSubGoal
{
	GENERATED_BODY()

	FGSubGoal();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FName, int32> SubGoals;

	bool operator==(const FGSubGoal& Goal) const
	{
		TArray<FName> Keys;
		TArray<FName> GoalKeys;
		SubGoals.GenerateKeyArray(Keys);
		Goal.SubGoals.GenerateKeyArray(GoalKeys);

		return Keys == GoalKeys;
	}
};

FORCEINLINE uint32 GetTypeHash(const FGSubGoal& b)
{
	return FCrc::MemCrc_DEPRECATED(&b, sizeof(FGSubGoal));
}
