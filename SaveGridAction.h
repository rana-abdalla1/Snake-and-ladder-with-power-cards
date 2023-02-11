#pragma once
#include "Action.h"
class SaveGridAction : public Action
{
	string fileName;
public:
	SaveGridAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~SaveGridAction();
};

