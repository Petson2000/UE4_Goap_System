// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GAction.h"
#include "AIBehaviorSettings.generated.h"

/**
 * 
 */
UCLASS()
class GOAP_SYSTEM_API UAIBehaviorSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UGAction*> AvailableActions;

};
