// Fill out your copyright notice in the Description page of Project Settings.


#include "G_SubGoal.h"

// Sets default values for this component's properties
UG_SubGoal::UG_SubGoal()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UG_SubGoal::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UG_SubGoal::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

