// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldState.h"

WorldState::WorldState()
{
}

WorldState::WorldState(FString inKey, int32 inValue)
{
	key = inKey;
	value = inValue;
}

WorldState::~WorldState()
{
}
