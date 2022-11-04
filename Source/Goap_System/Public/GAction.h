// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAction.generated.h"


UCLASS(ClassGroup = (Custom), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GOAP_SYSTEM_API UGAction : public UObject
{
	GENERATED_BODY()

public:	
	UGAction();

public:	

	UFUNCTION(BlueprintNativeEvent)
	bool PrePerform(AActor* PerformingActor);

	UFUNCTION(BlueprintNativeEvent)
	void PerformUpdate(AActor* PerformingActor);

	UFUNCTION(BlueprintNativeEvent)
	bool PostPerform(AActor* PerformingActor);

	virtual bool PrePerform_Implementation(AActor* PerformingActor);
	virtual void PerformUpdate_Implementation(AActor* PerformingActor);
	virtual bool PostPerform_Implementation(AActor* PerformingActor);

	bool IsAchievable();

	bool IsAchievableGiven(const TMap<FName, int32>& conditions);

	UFUNCTION(BlueprintCallable)
	void FinishAction(AActor* PerformingActor);

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GOAP")
	FName ActionName = "Action";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float Cost = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	FVector Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float Duration = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FName, int32> PreCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FName, int32> Effects;

	//What range the character has to be in to complete the action.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float Range = 5.0f;

	//Todo: Need a way to check current beliefs
	UPROPERTY(VisibleAnywhere, Category = "GOAP")
	bool bIsRunning = false;
};
