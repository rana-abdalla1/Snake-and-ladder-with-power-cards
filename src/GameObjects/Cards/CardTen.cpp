#include "CardTen.h"
Player* CardTen::owner = NULL;
bool CardTen::firstTime = true;
CardTen::CardTen(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 10;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardTen, click to continue");
	if (firstTime == true)
	{
		Card9_11::ReadCardParameters(pGrid);
		firstTime = false;
	}
}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid,pPlayer,owner);
}
int CardTen::GetcardPrice() 
{
	return cardPrice;
}
void CardTen::changeOwner(Player* ptr)
{
	owner = ptr;
}
void CardTen::resetowner()
{
	owner = NULL;
}
CardTen::~CardTen()
{
}
