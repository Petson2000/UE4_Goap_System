// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GInventory.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GOAP_SYSTEM_API UGInventory : public UObject
{
	GENERATED_BODY()
	
public:	
	UGInventory();

public:	

	UFUNCTION(BlueprintCallable)
	void InsertItemInInventory(AActor* Item);

	UFUNCTION(BlueprintCallable)
	AActor* GetItemOfClass(UClass* ItemClass);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TMap<AActor*, bool> Items;
};
