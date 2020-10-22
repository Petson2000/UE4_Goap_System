// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "G_SubGoal.generated.h"


UCLASS(ClassGroup = (Custom), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GOAP_SYSTEM_API UG_SubGoal : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UG_SubGoal();
	UG_SubGoal(FString s, int i, bool r);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<FString, int32> sGoals;

	bool bRemove;
		
};
