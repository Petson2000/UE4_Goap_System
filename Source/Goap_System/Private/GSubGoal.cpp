// Fill out your copyright notice in the Description page of Project Settings.


#include "GSubGoal.h"

GSubGoal::GSubGoal()
{
}

GSubGoal::GSubGoal(FString s, int i, bool r)
{
	sGoals.Add(s, i);
	bRemove = r;
}

GSubGoal::~GSubGoal()
{
}
