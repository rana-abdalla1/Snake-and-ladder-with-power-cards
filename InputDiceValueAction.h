#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class InputDiceValueAction : public Action
{
	int diceValue;
public:
	InputDiceValueAction (ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~InputDiceValueAction();
};

