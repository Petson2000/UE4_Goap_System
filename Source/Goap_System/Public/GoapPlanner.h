#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAction.h"
#include "WorldStateManager.h"
#include "GNode.h"
#include "GoapPlanner.generated.h"

UCLASS()
class GOAP_SYSTEM_API AGoapPlanner : public AActor
{
	GENERATED_BODY()
	
public:	
	AGoapPlanner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

	TArray<UGAction*> Plan(TArray<UGAction*> actions, TMap<FString, int32> goal, TMap<FString, int32> beliefs);

private:
	bool BuildGraph(GNode& parent, TArray<GNode> nodes, TArray<UGAction*> possibleActions, TMap<FString, int32> goal);

	TArray<UGAction*> ActionSubset(TArray<UGAction*> actions, UGAction* actionToRemove);


	bool GoalAchieved(TMap<FString, int32> goal, TMap<FString, int32> state);

public:
	AWorldStateManager* stateManager;

};
