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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool HasState(FString key, int32 value);

	UFUNCTION(BlueprintCallable)
	void AddState(FString key, int32 value);

	UFUNCTION(BlueprintCallable)
	void RemoveState(FString key);

	UFUNCTION(BlueprintCallable)
	void SetState(FString key, int32 value);

	UFUNCTION(BlueprintCallable)
	void ModifyState(FString key, int32 value);

	TMap<FString, int32> GetStates();

public:
	TMap<FString, int32> states;

};
