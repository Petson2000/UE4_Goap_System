// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GOAP_SYSTEM_API GNode
{
public:
	GNode();

	GNode(GNode* inParent, float inCost, TMap<FString, int32> states);

	GNode(GNode* inParent, float inCost, TMap<FString, int32> allStates, TMap<FString, int32> beliefStates);

	~GNode();

public: 

	GNode* parent;
	float cost;

	TMap<FString, int32> state;

	//Todo: we probably want this to hold a ref to an action somehow

};
