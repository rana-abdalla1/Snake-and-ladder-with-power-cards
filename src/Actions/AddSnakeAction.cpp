#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	while (true)
	{
		CellPosition temp = pIn->GetCellClicked();
		bool checkvalid = temp.IsValidCell();
		if (checkvalid)
		{
			startPos = temp;
			break;
		}
		else
			pGrid->PrintErrorMessage("You clicked on an invalid start cell, click another cell");
	}
	// Read the endPos parameter
	//check if endcell is valid
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	while (true)
	{
		CellPosition temp = pIn->GetCellClicked();
		bool checkvalid = temp.IsValidCell();
		if (checkvalid)
		{
			endPos = temp;
			break;
		}
		else
			pGrid->PrintErrorMessage("You clicked on an invalid end cell, ckick another cell");
	}


	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	//delete pSnake;
}
