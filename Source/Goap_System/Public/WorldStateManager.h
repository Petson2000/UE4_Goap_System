// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldStateManager.generated.h"

UCLASS()
class GOAP_SYSTEM_API AWorldStateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldStateManager();

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	bool HasState(FName Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void AddState(FName Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void RemoveState(FName Key);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void SetState(FName Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void ModifyState(FName Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	TMap<FName, int32> GetStates();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FName, int32> States;

};
