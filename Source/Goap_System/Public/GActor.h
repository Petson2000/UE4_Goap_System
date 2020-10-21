// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GAction.h"
#include "GSubGoal.h"
#include "WorldStateManager.h"
#include "GoapPlanner.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GActor.generated.h"

/**
 *
 */
UCLASS()
class GOAP_SYSTEM_API AGActor : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void Init(TArray<UGAction*> characterActions);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void CompleteAction();

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void Update();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UGAction*> actions;

	//UPROPERTY(EditAnywhere, Category = "GOAP")
	TMap<GSubGoal*, int32> goals;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GOAP")
	UGAction* currentAction;


	AWorldStateManager* stateManager;

	TMap<FString, int32> beliefs;

	AGoapPlanner* planner;

	TArray<UGAction*> actionQueue;

	GSubGoal* currentGoal;

private:

	bool bInvoked = false;
};