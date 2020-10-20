// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAction.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOAP_SYSTEM_API UGAction : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGAction();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GOAP")
	FString actionName = "Action";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	FVector target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float duration = 0;

	//Todo: Need to implement a version of worldstates here
	//Todo: Also need worldstate after effect for each action

	TMap<FString, int32> preConditions;
	TMap<FString, int32> effects;

	//Todo: Need a way to check current beliefs

	UPROPERTY(VisibleAnywhere, Category = "GOAP")
	bool running = false;

	bool isAchievable();

};
