#include "InputDiceValueAction.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{

}
void InputDiceValueAction::ReadActionParameters() //No validation needed as it is used for testing, players will not use it
{
	//Pointers to grid,input,output
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please input new dice value...");
	//Will set data member to input from the user
	diceValue = pIn->GetInteger(pOut);
	//Clear status bar
	pOut->ClearStatusBar();
}
void InputDiceValueAction::Execute()
{
	/*Get pointer to grid using app manager
	Grid* pGrid = pManager->GetGrid();
	//read parameters
	ReadActionParameters();
	//get pointer to curr player
	Player* currplayer = pGrid->GetCurrentPlayer();
	//The player will move himself
	currplayer->Move(pGrid, diceValue);
	//Go to the next player
	pGrid->AdvanceCurrentPlayer();*/
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game Already Ended, Cannot roll dice.");
	}
	// -- If not ended, do the following --:
	else
	{

		// 3- Get the "current" player from pGrid
		Player* currplayer = pGrid->GetCurrentPlayer();
		if (currplayer->GetFreeze() > 0) //if player is not affected by card 4
		{
			currplayer->IncrementTurn(); //Will go the next turn and reset freeze to 0
			pGrid->PrintErrorMessage("You cannot roll dice this turn, click to proceed to next player");
			pGrid->AdvanceCurrentPlayer(); //will advance to the next player
			return;
		}

		// 4- Move the currentPlayer using function Move of class player
		currplayer->Move(pGrid, diceValue);
		if (currplayer->GetmovingBack() == 1)
		{
			pGrid->PrintErrorMessage("You landed on card 5! You will move backward, click to continue");
			currplayer->MoveBackward(pGrid, diceValue);
			currplayer->SetmovingBack(0);
		}
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	}
	InputDiceValueAction::~InputDiceValueAction()
	{

	}
