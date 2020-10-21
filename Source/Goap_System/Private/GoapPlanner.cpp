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

TArray<UGAction*> AGoapPlanner::Plan(TArray<UGAction*> actions, TMap<FString, int32> goal, TMap<FString, int32> beliefs)
{
	TArray<UGAction*> useableActions;

	for (const auto& action : actions)
	{
		useableActions.Add(action);
	}

	TArray<GNode> nodes;

	GNode startNode(nullptr, 0.0f, stateManager->GetStates(), beliefs, nullptr);

	bool bSuccess = BuildGraph(startNode, nodes, actions, goal);

	if (!bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Planner was unable to make a plan!"));
		return {};
	}

	GNode cheapest;

	for (auto node : nodes)
	{
		if (node.cost < cheapest.cost)
		{
			cheapest = node;
		}
	}

	TArray<UGAction*> result;
	GNode* node = &cheapest;

	while (node != nullptr)
	{
		if (node->action != nullptr)
		{
			result.Add(node->action);
		}

		node = node->parent;
	}

	TArray<UGAction*> plan;

	for (const auto& action : result)
	{
		plan.Add(action);
	}

	UE_LOG(LogTemp, Log, TEXT("Planning was successful! Current plan includes %d tasks!"), plan.Num());

	return plan;
}

bool AGoapPlanner::BuildGraph(GNode& parent, TArray<GNode> nodes, TArray<UGAction*> possibleActions,TMap<FString, int32> goal)
{
	bool bFoundPath = false;

	for (const auto& action : possibleActions)
	{
		if (action->isAchievable())
		{
			TMap<FString, int32> currentState;

			currentState = parent.state;

			for (TPair<FString, int32> effect : action->effects)
			{
				if (!currentState.Contains(effect.Key))
				{
					currentState.Add(effect.Key, effect.Value);
				}
			}

			UGAction* act = action;
			GNode* parentPtr = &parent;

			GNode node(parentPtr, parent.cost + act->cost, currentState, act);

			if (GoalAchieved(goal, currentState))
			{
				nodes.Add(node);
				bFoundPath = true;
			}

			else
			{
				TArray<UGAction*> subset = ActionSubset(possibleActions, action);
				bool bFound = BuildGraph(node, nodes, subset, goal);

				if (bFound)
				{
					bFoundPath = true;
				}
			}
		}
	}

	return true;
}

TArray<UGAction*> AGoapPlanner::ActionSubset(TArray<UGAction*> actions, UGAction* actionToRemove)
{
	TArray<UGAction*> subset;

	for (const auto action : actions)
	{
		if (action != actionToRemove)
		{
			subset.Add(action);
		}
	}

	return subset;
}

bool AGoapPlanner::GoalAchieved(TMap<FString, int32> goal, TMap<FString, int32> state)
{
	for (TPair<FString, int32> g : goal)
	{
		if (!state.Contains(g.Key))
		{
			return false;
		}
	}

	return true;
}
