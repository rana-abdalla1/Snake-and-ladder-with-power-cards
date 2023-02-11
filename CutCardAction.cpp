#include "CutCardAction.h"
#include "Grid.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on cell to cut it");
	cutCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void  CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (cutCell.IsValidCell())
	{
		Card* cardtoclipboard = pGrid->copycard(cutCell);
		pGrid->SetClipboard(cardtoclipboard);
		pGrid->RemoveObjectFromCell(cutCell);
	}
	else
	{
		pGrid->PrintErrorMessage("You clicked on an invalid cell, click to continue");
	}
}
CutCardAction::~CutCardAction()
{

}
