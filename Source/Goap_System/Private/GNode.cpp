#include "GNode.h"


GNode::GNode(GNode* InParent, float InCost, TMap<FName, int32> InStates, UGAction* InAction)
{
	Parent = InParent;
	Cost = InCost;
	States = InStates;
	Action = InAction;
}

GNode::GNode(GNode* InParent, float InCost, const TMap<FName, int32>& AllStates, const TMap<FName, int32>& BeliefStates, UGAction* InAction)
{
	Parent = InParent;

	Cost = InCost;

	States = TMap<FName, int32>(AllStates);

	for (TPair<FName, int32> Pair : BeliefStates)
	{
		if (!States.Contains(Pair.Key))
		{
			States.Add(Pair);
		}
	}

	Action = InAction;
}

GNode::~GNode()
{
}
