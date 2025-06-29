#include "CopyCardAction.h"
#include "Grid.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on cell to copy it");
	copiedcell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (copiedcell.IsValidCell())
	{
		Card* cardtoclipboard = pGrid->copycard(copiedcell);
		pGrid->SetClipboard(cardtoclipboard);
	}
	else
	{
		pGrid->PrintErrorMessage("You clicked on an invalid cell, click to continue");
	}
}
CopyCardAction::~CopyCardAction()
{

}
