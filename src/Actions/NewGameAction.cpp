#include "NewGameAction.h"
#include "Grid.h"
NewGameAction::NewGameAction(ApplicationManager* pApp):Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->resetAllPlayers();
	pGrid->resetAllCities(); 
	//resets all players and cities in grid
	pGrid->PrintErrorMessage("New game started, Let's play, click to continue!");

}

NewGameAction::~NewGameAction()
{
}
