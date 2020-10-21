#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GOAP_SYSTEM_API GSubGoal
{
public:
	GSubGoal();
	GSubGoal(FString s, int i, bool r);
	~GSubGoal();

public:
	TMap<FString, int32> sGoals;

	bool bRemove;
};
