// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldState.h"

WorldState::WorldState()
{
}

WorldState::WorldState(FString InKey, int32 InValue)
{
	Key = InKey;
	Value = InValue;
}

WorldState::~WorldState()
{
}
