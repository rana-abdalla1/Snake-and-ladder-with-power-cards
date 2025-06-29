#include "PasteCardAction.h"
#include "Card.h"
#include "Grid.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on cell to paste it");
	destinationCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (destinationCell.IsValidCell())
	{
		Card* cardtoclipboard = pGrid->GetClipboard();
		cardtoclipboard->setposition(destinationCell);
		bool checkpaste = pGrid->AddObjectToCell(cardtoclipboard);
		if (!checkpaste)
			pGrid->PrintErrorMessage("Cell already has an object, cannot paste here, click to continue");
	}
	else
	{
		pGrid->PrintErrorMessage("You clicked on an invalid cell, click to continue");
	}

}

PasteCardAction::~PasteCardAction()
{
}
