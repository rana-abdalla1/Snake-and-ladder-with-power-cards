#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{

}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	//Check if start cell is valid
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");

		CellPosition temp1 = pIn->GetCellClicked();
		bool checkvalid1 = temp1.IsValidCell();
		if (checkvalid1)
		{
			startPos = temp1;
		}
		else
		{
			pGrid->PrintErrorMessage("You clicked on an invalid start cell, click another cell");
			pOut->ClearStatusBar();
			return;
		}

	// Read the endPos parameter
	//check if endcell is valid
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
		CellPosition temp2 = pIn->GetCellClicked();
		bool checkvalid2 = temp2.IsValidCell();
		if (checkvalid2)
		{
			endPos = temp2;
		}
		else
		{
			pGrid->PrintErrorMessage("You clicked on an invalid end cell, click to continue"); // no exectuion of addladderaction
			pOut->ClearStatusBar();
			return;
		}

	///TODO: Make the needed validations on the read parameters

		pOut->ClearStatusBar();

	// Clear messages
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	//delete pLadder;
}
