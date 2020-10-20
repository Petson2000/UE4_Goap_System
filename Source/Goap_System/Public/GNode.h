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
	GNode();

	GNode(GNode* inParent, float inCost, TMap<FString, int32> states, UGAction* action);

	GNode(GNode* inParent, float inCost, TMap<FString, int32> allStates, TMap<FString, int32> beliefStates, UGAction* action);

	~GNode();

public: 

	 GNode* parent;
	 float cost;

	TMap<FString, int32> state;

	TSubclassOf<UGAction> action;
};
