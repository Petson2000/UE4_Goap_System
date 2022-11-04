#include "GoapPlanner.h"

UGoapPlanner::UGoapPlanner()
{
}

void UGoapPlanner::Initialize(FSubsystemCollectionBase& Collection)
{
	StateManager = Cast<AWorldStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorldStateManager::StaticClass()));
}

TArray<UGAction*> UGoapPlanner::Plan(TArray<UGAction*> Actions, const TMap<FName, int32>& Goal, const TMap<FName, int32>& Beliefs)
{
	//Empty nodes before making a new plan to make sure we dont use past information.
	Nodes.Empty();

	TArray<UGAction*> useableActions;
	
	for (const auto& Action : Actions)
	{
		if (Action->IsAchievable())
		{
			useableActions.Add(Action);
		}
	}

	GNode* StartNode = new GNode(nullptr, 0.0f, StateManager->GetStates(), Beliefs, nullptr);
	bool bSuccess = BuildGraph(StartNode, Nodes, Actions, Goal);

	if (!bSuccess)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Planning failed, no plan found:"));
		return {};
	}

	GNode* Cheapest = new GNode();

	Cheapest->Cost = HUGE_VALF;

	if (Nodes.Num() > 0)
	{
		for (auto Node : Nodes)
		{
			if (Node->Cost < Cheapest->Cost)
			{
				Cheapest = Node;
			}
		}
	}

	TArray<UGAction*> Result;
	GNode* Node = Cheapest;

	while (Node != nullptr)
	{
		if (Node->Action != nullptr)
		{
			Result.Insert(Node->Action, 0);
		}

		Node = Node->Parent;
	}

	TArray<UGAction*> Plan{};

	for (const auto& Action : Result)
	{
		Plan.Add(Action);
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Planning complete, nodes: " + FString::FromInt(Plan.Num())));

	return Plan;
}

bool UGoapPlanner::BuildGraph(GNode* Parent, TArray<GNode*>& NodeList, TArray<UGAction*> PossibleActions, TMap<FName, int32> Goal)
{
	bool bFoundPath = false;

	for (const auto Action : PossibleActions)
	{
		if (Action->IsAchievableGiven(Parent->States))
		{
			TMap<FName, int32> CurrentState(Parent->States);

			for (const auto& Effect : Action->Effects)
			{
				if (!CurrentState.Contains(Effect.Key))
				{
					CurrentState.Add(Effect.Key, Effect.Value);
				}
			}

			GNode* Node = new GNode(Parent, Parent->Cost + Action->Cost, CurrentState, Action);

			if (GoalAchieved(Goal, CurrentState))
			{
				NodeList.Add(Node);
				bFoundPath = true;
			}

			else
			{
				TArray<UGAction*> SubSet = ActionSubset(PossibleActions, Action);
				bool bFound = BuildGraph(Node, NodeList, SubSet, Goal);

				if (bFound)
				{
					bFoundPath = true;
				}
			}
		}
	}

	return bFoundPath;
}

TArray<UGAction*> UGoapPlanner::ActionSubset(TArray<UGAction*>& Actions, UGAction* ActionToRemove)
{
	TArray<UGAction*> SubSet;

	for (const auto& Action : Actions)
	{
		if (Action != ActionToRemove)
		{
			SubSet.Add(Action);
		}
	}

	return SubSet;
}

bool UGoapPlanner::GoalAchieved(TMap<FName, int32> Goal, TMap<FName, int32> State)
{
	for (const auto& SubGoal : Goal)
	{
		if (!State.Contains(SubGoal.Key))
		{
			return false;
		}
	}

	return true;
}
