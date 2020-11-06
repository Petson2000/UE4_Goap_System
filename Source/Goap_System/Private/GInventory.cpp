#include "GInventory.h"

AGInventory::AGInventory()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGInventory::InsertItemInInventory(AActor* Item)
{
	if (Item != nullptr)
	{
		items.Add(Item, false);
	}
}

AActor* AGInventory::GetItemOfClass(UClass* ItemClass)
{
	for (auto pair : items)
	{
		if (pair.Key->IsA(ItemClass) && !pair.Value)
		{
			pair.Value = true;
			return pair.Key;
		}
	}

	return nullptr;
}