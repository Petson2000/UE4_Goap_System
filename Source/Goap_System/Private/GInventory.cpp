#include "GInventory.h"

UGInventory::UGInventory()
{

}

void UGInventory::InsertItemInInventory(AActor* Item)
{
	if (Item != nullptr)
	{
		Items.Add(Item, false);
	}
}

AActor* UGInventory::GetItemOfClass(UClass* ItemClass)
{
	for (auto pair : Items)
	{
		if (pair.Key->IsA(ItemClass) && !pair.Value)
		{
			pair.Value = true;
			return pair.Key;
		}
	}

	return nullptr;
}