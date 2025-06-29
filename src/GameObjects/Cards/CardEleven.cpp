#include "CardEleven.h"
Player* CardEleven::owner = NULL;
bool CardEleven::firstTime = true;
CardEleven::CardEleven(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 11;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardEleven, click to continue");
	if (firstTime == true)
	{
		Card9_11::ReadCardParameters(pGrid);
		firstTime = false;
	}
}
int CardEleven::GetcardPrice()
{
	return cardPrice;
}
void CardEleven::changeOwner(Player* ptr)
{
	owner = ptr;
}
void CardEleven::resetowner()
{
	owner = NULL;
}
CardEleven::~CardEleven()
{
}