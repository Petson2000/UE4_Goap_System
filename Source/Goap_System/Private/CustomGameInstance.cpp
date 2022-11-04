// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"

void UCustomGameInstance::Init()
{
	WorldInventory = NewObject<UGInventory>();
}
