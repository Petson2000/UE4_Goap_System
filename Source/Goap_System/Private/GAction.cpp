// Fill out your copyright notice in the Description page of Project Settings.


#include "GAction.h"

// Sets default values for this component's properties
UGAction::UGAction()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGAction::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGAction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGAction::isAchievable()
{
	return true;
}

