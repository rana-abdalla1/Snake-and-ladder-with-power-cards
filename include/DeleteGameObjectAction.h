#pragma once
#include "Action.h"
class DeleteGameObjectAction : public Action
{
	CellPosition deletedCell;
public:
	DeleteGameObjectAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~DeleteGameObjectAction();
};

