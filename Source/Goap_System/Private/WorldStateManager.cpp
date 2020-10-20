// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateManager.h"

// Sets default values
AWorldStateManager::AWorldStateManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWorldStateManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldStateManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FORCEINLINE bool AWorldStateManager::HasState(FString key, int32 value)
{
	return states.Contains(key);
}

FORCEINLINE void AWorldStateManager::AddState(FString key, int32 value)
{
	states.Add(key, value);
}

void AWorldStateManager::RemoveState(FString key)
{
	if (states.Contains(key))
	{
		states.Remove(key);
	}
}

void AWorldStateManager::SetState(FString key, int32 value)
{
	if (states.Contains(key))
	{
		states[key] = value;
	}

	else
	{
		states.Add(key, value);
	}
}

void AWorldStateManager::ModifyState(FString key, int32 value)
{
	if (states.Contains(key))
	{
		states[key] += value;

		if (states[key] <= 0)
		{
			RemoveState(key);
		}
	}

	else
	{
		states.Add(key, value);
	}
}

TMap<FString, int32> AWorldStateManager::GetStates()
{
	return states;
}

