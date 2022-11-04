// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GInventory.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GOAP_SYSTEM_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UGInventory* GetWorldInventory() { return WorldInventory; }

protected:
	virtual void Init() override;
	
private:
	UPROPERTY()
	UGInventory* WorldInventory;

};
