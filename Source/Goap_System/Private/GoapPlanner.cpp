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

	stateManager = Cast<AWorldStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorldStateManager::StaticClass()));
}

// Called every frame
void AGoapPlanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<UGAction*> AGoapPlanner::Plan(TArray<UGAction*> actions, const TMap<FString, int32>& goal, TMap<FString, int32> beliefs, UGAction* startingAction)
{
	nodes.Empty();

	TArray<UGAction*> useableActions;

	for (const auto& action : actions)
	{
		if (action->isAchievable())
		{
			useableActions.Add(action);
		}
	}


	GNode* startNode = new GNode(nullptr, 0.0f, stateManager->GetStates(), beliefs, nullptr);
	bool bSuccess = BuildGraph(startNode, nodes, actions, goal);

	if (!bSuccess)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Planning failed, no plan found:"));
		return {};
	}

	GNode* cheapest = new GNode();

	cheapest->cost = HUGE_VALF;

	if (nodes.Num() > 0)
	{
		for (auto node : nodes)
		{
			if (node->cost < cheapest->cost)
			{
				cheapest = node;
			}
		}
	}

	TArray<UGAction*> result;
	GNode* node = cheapest;

	while (node != nullptr)
	{
		if (node->action != nullptr)
		{
			result.Insert(node->action, 0);
		}

		node = node->parent;
	}

	TArray<UGAction*> plan{};

	for (const auto& action : result)
	{
		plan.Add(action);
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Planning complete, nodes: " + FString::FromInt(plan.Num())));
	return plan;
}

bool AGoapPlanner::BuildGraph(GNode* parent, TArray<GNode*>& nodeList, TArray<UGAction*> possibleActions, TMap<FString, int32> goal)
{
	bool bFoundPath = false;

	for (const auto action : possibleActions)
	{
		if (action->isAchievableGiven(parent->states))
		{
			TMap<FString, int32> currentState(parent->states);

			for (const auto& effect : action->effects)
			{
				if (!currentState.Contains(effect.Key))
				{
					currentState.Add(effect.Key, effect.Value);
				}
			}

			//auto act = action;

			//GNode* parentPtr = parent;
			GNode* node = new GNode(parent, parent->cost + action->cost, currentState, action);

			if (GoalAchieved(goal, currentState))
			{
				nodeList.Add(node);
				bFoundPath = true;
			}

			else
			{
				TArray<UGAction*> subset = ActionSubset(possibleActions, action);
				bool bFound = BuildGraph(node, nodeList, subset, goal);

				if (bFound)
				{
					bFoundPath = true;
				}
			}
		}
	}

	return bFoundPath;
}

TArray<UGAction*> AGoapPlanner::ActionSubset(TArray<UGAction*>& actions, UGAction* actionToRemove)
{
	TArray<UGAction*> subset;

	for (const auto& action : actions)
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
	for (const auto& g : goal)
	{
		if (!state.Contains(g.Key))
		{
			return false;
		}
	}

	return true;
}
