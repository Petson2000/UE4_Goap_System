// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GAction.h"
#include "CoreMinimal.h"

/**
 * 
 */
class GOAP_SYSTEM_API GNode
{
public:
	GNode() = default;

	GNode(GNode* inParent, float inCost, TMap<FString, int32> states, UGAction* inAction);

	GNode(GNode* inParent, float inCost, const TMap<FString, int32>& allStates, const TMap<FString, int32>& beliefStates, UGAction* inAction);

	~GNode();

public: 

	 GNode* parent = nullptr;
	 float cost = 0.0f;

	TMap<FString, int32> states;

	UGAction* action = nullptr
		;
};
