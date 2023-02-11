#pragma once
#include "CardSeven.h"
#include "CellPosition.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}
void CardSeven::ReadCardParameters(Grid* pGrid) // No parameters
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)// Sends player whose position after current player to cell 1
{
	Card::Apply(pGrid, pPlayer);//Calls Base Class "Card" Apply to print message indicating that the player stopped at this card
	Player* pNextPlayer = pGrid->GetNextPlayer(pPlayer);//Uses Function GetNextPlayer to find next player on the grid
	if (pNextPlayer == NULL)
	{
		pGrid->PrintErrorMessage( "No player infront of you no player will be sent to cell 1, cllick to continue" );
		return;
	}
	CellPosition pCellPosition;
	pCellPosition = CellPosition::GetCellPositionFromNum(1);// creates a position object that has cell num =1
	pGrid->PrintErrorMessage("Next Player infront of you will be sent to cell 1, click to continue");
	pGrid->UpdatePlayerCell(pNextPlayer, pCellPosition); // uses this cell position to update the next players cell
	pNextPlayer->SetStepCount(1);// updates player step count
}
CardSeven::~CardSeven()// Empty Destrcutor No Dynamic Allocation
{

}