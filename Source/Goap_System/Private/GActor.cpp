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

	planner = Cast<AGoapPlanner>(UGameplayStatics::GetActorOfClass(GetWorld(), AGoapPlanner::StaticClass()));

	if (stateManager == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldStateManager could not be set!"));
	}

	if (planner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Planner could not be set!"));
	}

	actions.Append(characterActions);
	bInvoked = false;
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
		if (FVector::Distance(GetPawn()->GetActorLocation(), currentAction->target) < currentAction->range)
		{
				StopMovement();
				CompleteAction();
		}

		return;
	}

	if (actionQueue.Num() <= 0)
	{
		for (auto goal : goals)
		{
			if (goal.Key != NULL)
			{
				actionQueue = planner->Plan(actions, goal.Key->sGoals, beliefs, standardAction);

				//Plan exists
				if (actionQueue.Num() > 0)
				{
					currentGoal = goal.Key;
					break;
				}
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
		if (currentAction != nullptr)
		{
			if (currentAction->PrePerform())
			{
				actionQueue.Remove(currentAction);
				currentAction->running = true;
				GetPawn()->SetActorRotation(currentAction->target.Rotation());
				MoveToLocation(currentAction->target, false, true);
			}

			else
			{
				actionQueue.Empty();
			}
		}
	}

	
}


