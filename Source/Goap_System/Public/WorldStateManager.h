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

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	bool HasState(FString key, int32 value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void AddState(FString key, int32 value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void RemoveState(FString key);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void SetState(FString key, int32 value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	void ModifyState(FString key, int32 value);

	UFUNCTION(BlueprintCallable, Category = "GOAP")
	TMap<FString, int32> GetStates();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FString, int32> states;

};
