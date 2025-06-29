#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) : Card(pos) 
{
	cardNumber = 5;
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->SetmovingBack(1);
	Card::Apply(pGrid, pPlayer);
}
void CardFive::ReadCardParameters(Grid* pGrid)
{
	//no parameters here
}
CardFive::~CardFive()
{}
