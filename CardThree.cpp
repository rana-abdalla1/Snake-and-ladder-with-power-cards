#include "CardThree.h"
#include"Grid.h"
#include"Player.h"
#include"RollDiceAction.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
	//no implementation here
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->DecreaseCurrentPlayer();
	pGrid->PrintErrorMessage("You got an extra turn!, click and roll the dice");
}
CardThree::~CardThree()
{}