// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateManager.h"

// Sets default values
AWorldStateManager::AWorldStateManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

FORCEINLINE bool AWorldStateManager::HasState(FName key, int32 value)
{
	return States.Contains(key);
}

FORCEINLINE void AWorldStateManager::AddState(FName key, int32 value)
{
	States.Add(key, value);
}

void AWorldStateManager::RemoveState(FName key)
{
	if (States.Contains(key))
	{
		States.Remove(key);
	}
}

void AWorldStateManager::SetState(FName key, int32 value)
{
	if (States.Contains(key))
	{
		States[key] = value;
	}

	else
	{
		States.Add(key, value);
	}
}

void AWorldStateManager::ModifyState(FName key, int32 value)
{
	if (States.Contains(key))
	{
		States[key] += value;

		if (States[key] <= 0)
		{
			RemoveState(key);
		}
	}

	else
	{
		States.Add(key, value);
	}
}

TMap<FName, int32> AWorldStateManager::GetStates()
{
	return States;
}

