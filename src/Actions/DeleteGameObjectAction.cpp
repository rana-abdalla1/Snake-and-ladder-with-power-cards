#include "DeleteGameObjectAction.h"
#include "Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{

}
void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	deletedCell = pIn->GetCellClicked();
}
void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (!deletedCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("You clicked on an invalid cell, click to continue");
		return;
	}
	bool valid=pGrid->RemoveObjectFromCell(deletedCell);
	if(valid)
	{
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Cell cleared succcessfully, click to continue");
	}
	else
	{
		pGrid->PrintErrorMessage("Cell already empty, click to continue");
	}
}
DeleteGameObjectAction::~DeleteGameObjectAction()

{

}