// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GAction.h"
#include "G_SubGoal.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<UG_SubGoal*, int32> goals;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GOAP")
	UGAction* currentAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	UGAction* standardAction;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GOAP")
		AWorldStateManager* stateManager;

	TMap<FString, int32> beliefs;

	AGoapPlanner* planner;

	TArray<UGAction*> actionQueue;

	UG_SubGoal* currentGoal;

private:

	bool bInvoked = false;
};
