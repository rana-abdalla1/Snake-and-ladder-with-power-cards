#include "CardEight.h"
CardEight::CardEight(const CellPosition& pos): Card(pos)
{
	cardNumber = 8;
}
void CardEight::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("Enter Fees To Get Out Of Prison, click to continue");
	int temp = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	while (temp <= 0)
	{
		pGrid->PrintErrorMessage("Invalid, Please Enter A Positive Value, click to continue ");
		temp = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	}
	Fees = temp;
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (pPlayer->GetWallet() >= Fees)
	{

		pGrid->PrintErrorMessage("Would You Like To Pay" + to_string(Fees) + " To Get Out Of Prison? Click Then, Enter 1 for Yes or 2 for No, click to continue");
		int Decision = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		while (Decision != 1 && Decision != 2)
		{
			pGrid->PrintErrorMessage("Invalid Please Enter 1 for Yes or 2 for No, click to continue");
			Decision = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		}
		if (Decision == 1)
		{
			pPlayer->decrementWallet(Fees);//decrements player wallet by fees
			pGrid->PrintErrorMessage("You Have Selected Yes, Current Wallet Amount is " + to_string(pPlayer->GetWallet())+"click to continue");
		}
		else if (Decision == 2)
		{
			pPlayer->SetFreeze(3);
			pGrid->PrintErrorMessage("You Have Selected No, You Will be Imprisoned for 3 rounds, click to continue ");
		}
		
	
	}
	else
	{
		pPlayer->SetFreeze(3);
		pGrid->PrintErrorMessage("Insufficient Funds in Wallet To Pay Fees, You Will be Imprisoned for 3 rounds, click to continue ");
	}
}
CardEight::~CardEight()
{

}