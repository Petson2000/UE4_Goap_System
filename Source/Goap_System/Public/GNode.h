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

	GNode(GNode* InParent, float InCost, TMap<FName, int32> States, UGAction* InAction);

	GNode(GNode* inParent, float inCost, const TMap<FName, int32>& allStates, const TMap<FName, int32>& beliefStates, UGAction* inAction);

	~GNode();

public: 

	 GNode* Parent = nullptr;
	 float Cost = 0.0f;

	TMap<FName, int32> States;

	UGAction* Action = nullptr
		;
};
