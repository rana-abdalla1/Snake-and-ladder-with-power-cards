#pragma once
#include "Action.h"
class CutCardAction : public Action
{
	CellPosition cutCell;
	public:
	CutCardAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~CutCardAction();
};

