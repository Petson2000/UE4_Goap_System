#include "GNode.h"

GNode::GNode()
{
}

GNode::GNode(GNode* inParent, float inCost, TMap<FString, int32> inStates, UGAction* action)
{
	parent = inParent;
	cost = inCost;
	states = states;
}

GNode::GNode(GNode* inParent, float inCost, const TMap<FString, int32>& allStates, const TMap<FString, int32>& beliefStates, UGAction* inAction)
{
	if (inParent != nullptr)
	{
		parent = inParent;
	}

	cost = inCost;


	states = allStates;

	//for (TPair<FString, int32> pair : beliefStates)
	//{
	//	if (!states.Contains(pair.Key))
	//	{
	//		states.Add(pair);
	//	}
	//}

	if (inAction != nullptr)
	{
		action = inAction;
	}
}

GNode::~GNode()
{
}
