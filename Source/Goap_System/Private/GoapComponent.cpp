#include "GoapComponent.h"

void UGoapComponent::Init(TArray<UGAction*> CharacterActions)
{
	Actions.Append(Settings->AvailableActions);

	StateManager = Cast<AWorldStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorldStateManager::StaticClass()));
	Planner = GetWorld()->GetGameInstance()->GetSubsystem<UGoapPlanner>();

	if (StateManager == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldStateManager could not be set!"));
	}

	if (Planner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Planner could not be set!"));
	}

	Actions.Append(CharacterActions);

	Inventory = CreateDefaultSubobject<UGInventory>(TEXT("Inventory"));

	bInvoked = false;
}

void UGoapComponent::CompleteAction()
{
	CurrentAction->bIsRunning = false;
	CurrentAction->PostPerform(GetOwner());
	bInvoked = false;
}

void UGoapComponent::Update()
{
	Beliefs = StateManager->GetStates();

	if (CurrentAction != nullptr && CurrentAction->bIsRunning)
	{
		return;
	}

	if (ActionQueue.Num() <= 0)
	{
		for (auto Goal : Goals)
		{
			if (Goal.Key.SubGoals.Num() > 0)
			{
				ActionQueue = Planner->Plan(Actions, Goal.Key.SubGoals, Beliefs);

				//Plan exists
				if (ActionQueue.Num() > 0)
				{
					CurrentGoal = Goal.Key;
					break;
				}
			}
		}
	}

	//We are out of actions
	if (ActionQueue.Num() == 0)
	{
		if (CurrentGoal.SubGoals.Num() > 0)
		{
			/*if (CurrentGoal->bRemove)
			{
				Goals.Remove(CurrentGoal);
			}*/
		}
	}

	else if (ActionQueue.Num() > 0)
	{
		CurrentAction = ActionQueue[0];
		if (CurrentAction != nullptr)
		{
			if (CurrentAction->PrePerform(GetOwner()))
			{
				ActionQueue.Remove(CurrentAction);
				CurrentAction->bIsRunning = true;
				//GetOwner()->bUseControllerRotationRoll = false;
				//GetOwner()->SetActorRotation(CurrentAction->target.Rotation());
				//GetOwner()->GetInstigatorController()->MoveToLocation(CurrentAction->target, false, true);
			}

			else
			{
				ActionQueue.Empty();
			}
		}
	}

	
}


