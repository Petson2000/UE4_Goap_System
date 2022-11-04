#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAction.h"
#include "WorldStateManager.h"
#include "GNode.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GoapPlanner.generated.h"

UCLASS()
class GOAP_SYSTEM_API UGoapPlanner : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:	
	UGoapPlanner();

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:

	TArray<UGAction*> Plan(TArray<UGAction*> Actions, const TMap<FName, int32>& Goal, const TMap<FName, int32>& Beliefs);

private:
	bool BuildGraph(GNode* Parent, TArray<GNode*>& NodeList, TArray<UGAction*> PossibleActions, TMap<FName, int32> Goal);

	TArray<UGAction*> ActionSubset(TArray<UGAction*>& Actions, UGAction* ActionToRemove);

	TArray<GNode*> Nodes;


	bool GoalAchieved(TMap<FName, int32> Goal, TMap<FName, int32> State);

public:
	AWorldStateManager* StateManager;

};
