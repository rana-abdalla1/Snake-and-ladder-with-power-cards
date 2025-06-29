#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>
SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp)
{

}
void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	fileName = pIn->GetSrting(pOut);
}
void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ofstream myfile;
	myfile.open(fileName);
	pGrid->SaveAll(myfile, LADDER);
	pGrid->SaveAll(myfile, SNAKE);
	myfile.close();
}
SaveGridAction::~SaveGridAction()
{

}