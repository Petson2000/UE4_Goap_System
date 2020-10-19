#include "GNode.h"

GNode::GNode()
{
}

GNode::GNode(GNode* inParent, float inCost, TMap<FString, int32> states)
{
	parent = inParent;
	cost = inCost;
	state = states;
}

GNode::GNode(GNode* inParent, float inCost, TMap<FString, int32> allStates, TMap<FString, int32> beliefStates)
{
	parent = inParent;
	cost = inCost;
	state = allStates;

	for (TPair<FString, int32> pair : beliefStates)
	{
		if (!state.Contains(pair.Key))
		{
			state.Add(pair);
		}
	}
}

GNode::~GNode()
{
}
