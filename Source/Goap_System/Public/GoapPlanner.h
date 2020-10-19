#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoapPlanner.generated.h"

UCLASS()
class GOAP_SYSTEM_API AGoapPlanner : public AActor
{
	GENERATED_BODY()
	
public:	
	AGoapPlanner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

};
