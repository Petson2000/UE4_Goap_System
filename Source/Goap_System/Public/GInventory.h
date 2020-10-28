// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GInventory.generated.h"

UCLASS()
class GOAP_SYSTEM_API AGInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	template<class T>
	static FORCEINLINE T GetItem(T)
	{
		items.FindItemByClass(T);
		if (T != nullptr)
		{
			return T();
		}
	
		return {};
	}

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	TArray<AActor*> items;
};
