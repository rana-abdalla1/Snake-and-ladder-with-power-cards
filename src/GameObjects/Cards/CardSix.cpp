#include "CardSix.h"
#include "CellPosition.h"
#include"Ladder.h"
#include"Snake.h"
CardSix::CardSix(const CellPosition& pos) : Card(pos)// Sets Card Number
{
	cardNumber = 6;
}
void CardSix::ReadCardParameters(Grid* pGrid) // Reads the parameters of CardSix which is: FinalPos
{

	pGrid->GetOutput()->PrintMessage("Click on Cell to move to");
	CellPosition CPtemp = pGrid->GetInput()->GetCellClicked();//Gets Cell to Move to from User
	//int Inttemp = CellPosition::GetCellNumFromPosition(CPtemp);// Converts the Cellpostion to the CellNumber and stores it Temp for Cell Number to be Validated
	while (!CPtemp.IsValidCell())// Checks That its a Valid Cell
	{
		pGrid->GetOutput()->PrintMessage("Invalid CellNumber Please click on a valid Cell ");
		CPtemp = pGrid->GetInput()->GetCellClicked();
	}

	FinalPos = CPtemp;
	pGrid->GetOutput()->ClearStatusBar();
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)//Moves Current Player to a specific cell
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->Moveapply(pGrid, FinalPos);

}
CardSix::~CardSix()
{

}