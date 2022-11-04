#include "GAction.h"

UGAction::UGAction()
{
}

bool UGAction::IsAchievable()
{
	return true;
}

bool UGAction::IsAchievableGiven(const TMap<FName, int32>& Conditions)
{
	for (const auto& Pair : PreCondition)
	{
		if (!Conditions.Contains(Pair.Key))
		{
			return false;
		}
	}
	return true;
}

void UGAction::FinishAction(AActor* PerformingActor)
{
	PostPerform(PerformingActor);
	bIsRunning = false;
}


bool UGAction::PrePerform_Implementation(AActor* PerformingActor)
{
	return true;
}

void UGAction::PerformUpdate_Implementation(AActor* PerformingActor)
{

}

bool UGAction::PostPerform_Implementation(AActor* PerformingActor)
{
	return true;
}