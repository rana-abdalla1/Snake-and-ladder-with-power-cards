#pragma once
#include "Action.h"
class PasteCardAction : public Action
{
	CellPosition destinationCell;
public:
	PasteCardAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~PasteCardAction();
};

