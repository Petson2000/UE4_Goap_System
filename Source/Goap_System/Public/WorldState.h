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
	WorldState(FString InKey, int32 InValue);
	~WorldState();

public:

	FString Key;
	int32 Value;
};
