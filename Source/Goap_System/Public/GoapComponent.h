// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GAction.h"
#include "G_SubGoal.h"
#include "WorldStateManager.h"
#include "GoapPlanner.h"
#include "GInventory.h"
#include "NavMesh/RecastNavMesh.h"
#include "AIBehaviorSettings.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GoapComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GOAP_SYSTEM_API UGoapComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void Init(TArray<UGAction*> CharacterActions);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void CompleteAction();

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void Update();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Actions")
	UAIBehaviorSettings* Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FGSubGoal, int32> Goals;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GOAP")
	UGAction* CurrentAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GOAP")
	AWorldStateManager* StateManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	UGInventory* Inventory;

	TMap<FName, int32> Beliefs;

	UGoapPlanner* Planner;

	TArray<UGAction*> ActionQueue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GOAP")
	FGSubGoal CurrentGoal;

private:
	bool bInvoked = false;

	UPROPERTY()
	TArray<UGAction*> Actions;
};
