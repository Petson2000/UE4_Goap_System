// Fill out your copyright notice in the Description page of Project Settings.


#include "GActor.h"

void AGActor::Init(TArray<UGAction*> characterActions)
{
	auto array = GetPawn()->GetComponentsByClass(UGAction::StaticClass());

	TArray<UGAction*> acts;

	for (auto act : array)
	{
		acts.Add(Cast<UGAction>(act));
	}

	stateManager = Cast<AWorldStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorldStateManager::StaticClass()));

	if (stateManager == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldStateManager could not be set!"));
	}

	actionQueue.Append(characterActions);
}

void AGActor::CompleteAction()
{
	currentAction->running = false;
	currentAction->PostPerform();
	bInvoked = false;
}

void AGActor::Update()
{
	beliefs = stateManager->GetStates();

	if (currentAction != nullptr && currentAction->running)
	{
		CompleteAction();
		bInvoked = true; 
	}

	if (actionQueue.Num() <= 0)
	{
		for (auto goal : goals)
		{
			actionQueue = planner->Plan(actions, goal.Key->sGoals, beliefs);

			//Plan exists
			if (actionQueue.Num() > 0)
			{
				currentGoal = goal.Key;
				break;
			}
		}
	}

	//We are out of actions
	if (actionQueue.Num() == 0)
	{
		if (currentGoal != nullptr)
		{
			if (currentGoal->bRemove)
			{
				goals.Remove(currentGoal);
			}
			planner = nullptr;

		}
	}

	else if (actionQueue.Num() > 0)
	{
		currentAction = actionQueue[0];
		if (currentAction->PrePerform())
		{
			currentAction->running = true;
			GetPawn()->AddMovementInput(currentAction->target, 1.0f, false);

			//if (GetPawn()->GetActorLocation() == currentAction->target)
			//{
			//
			//}
		}
	}

	else
	{
		actionQueue.Empty();
	}
}


