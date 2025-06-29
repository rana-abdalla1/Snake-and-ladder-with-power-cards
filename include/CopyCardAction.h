#pragma once
#include "Action.h"
class CopyCardAction : public Action
{
	CellPosition copiedcell;
public:
	CopyCardAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~CopyCardAction();
};

