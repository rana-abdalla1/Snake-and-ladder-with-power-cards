#include "Card9_11.h"
#include "CardNine.h"
Player* CardNine::owner = NULL;
 bool CardNine:: firstTime=true;
CardNine::CardNine(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardNine, click to continue");
	if (firstTime == true)
	{
		Card9_11::ReadCardParameters(pGrid);
		firstTime = false;
	}
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer, owner);
}
int CardNine::GetcardPrice() 
{
	return cardPrice;
}
void CardNine::changeOwner(Player* ptr)
{
	owner = ptr;
}
void CardNine::resetowner()
{
	owner = NULL;
}
CardNine::~CardNine()
{
}
