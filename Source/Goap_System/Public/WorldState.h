// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GOAP_SYSTEM_API WorldState
{
public:
	WorldState();
	WorldState(FString inKey, int32 inValue);
	~WorldState();

public:

	FString key;
	int32 value;
};
