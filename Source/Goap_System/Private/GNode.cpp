#include "GNode.h"


GNode::GNode(GNode* inParent, float inCost, TMap<FString, int32> inStates, UGAction* inAction)
{
	parent = inParent;
	cost = inCost;
	states = inStates;
	action = inAction;
}

GNode::GNode(GNode* inParent, float inCost, const TMap<FString, int32>& allStates, const TMap<FString, int32>& beliefStates, UGAction* inAction)
{
	parent = inParent;

	cost = inCost;

	states = TMap<FString, int32>(allStates);

	for (TPair<FString, int32> pair : beliefStates)
	{
		if (!states.Contains(pair.Key))
		{
			states.Add(pair);
		}
	}

	action = inAction;
}

GNode::~GNode()
{
}
