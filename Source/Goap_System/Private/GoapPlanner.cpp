// Fill out your copyright notice in the Description page of Project Settings.


#include "GoapPlanner.h"

// Sets default values
AGoapPlanner::AGoapPlanner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoapPlanner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoapPlanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<TSubclassOf<UGAction>> AGoapPlanner::Plan(TArray<TSubclassOf<UGAction>> actions, TMap<FString, int32> goal, TMap<FString, int32> beliefs)
{
	TArray<TSubclassOf<UGAction>> useableActions;

	for (TSubclassOf<UGAction> action : actions)
	{
		if (Cast<UGAction>(action))
		{
				useableActions.Add(action);
		}
	}

	TArray<GNode> nodes;

	GNode startNode = { nullptr, 0, stateManager->GetStates(), beliefs, nullptr };

	bool bSuccess = BuildGraph(startNode, nodes, actions, goal);

	//if (!bSuccess)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Planner was unable to make a plan!"));
	//	return TArray<TSubclassOf<UGAction>>();
	//}

	GNode cheapest;

	for (GNode& node : nodes)
	{
		if (node.cost < cheapest.cost)
		{
			cheapest = node;
		}
	}

	TArray<TSubclassOf<UGAction>> result;

	GNode* node = &cheapest;

	while (node != nullptr)
	{
		if (node->action != nullptr)
		{
			result.Add(node->action);
		}

		node = node->parent;
	}

	TArray<TSubclassOf<UGAction>> plan;

	for (TSubclassOf<UGAction> action : result)
	{
		plan.Add(action);
	}

	UE_LOG(LogTemp, Log, TEXT("Planning was successful! Current plan includes %d tasks!"), plan.Num());

	return plan;
}

bool AGoapPlanner::BuildGraph(const GNode& parent, TArray<GNode> nodes, TArray<TSubclassOf<UGAction>> possibleActions, TMap<FString, int32> goal)
{
	bool bFoundPath = false;

	for (TSubclassOf<UGAction> action : possibleActions)
	{
		if (Cast<UGAction>(action)->isAchievable())
		{
			TMap<FString, int32>  currentState;

			for (TPair<FString, int32> eff : Cast<UGAction>(action)->effects)
			{
				//if(!currentState.Contains())
			}

		}
	}

	return true;
}
