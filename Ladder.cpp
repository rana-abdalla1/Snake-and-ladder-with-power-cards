#include "Ladder.h"
#include "CMUgraphicsLib\CMUgraphics.h"
int Ladder::ladderscount = 0;
bool Ladder::saved = false; //to save file only once
Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	type = LADDER;
	ladderscount++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Save(ofstream& Outfile, Type t)
{
	if (saved == false)
	{
		Outfile << ladderscount << endl;
		saved = true;
	}
	if (t == LADDER)
		Outfile << position.GetCellNum() << "  " << endCellPos.GetCellNum() << endl;
}

int Ladder::getLaddersCount()
{
	return ladderscount;
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	//This function already calls GetPointClicked at the end
	pGrid->PrintErrorMessage("You have reached a ladder, click to continue");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	//    Review the "pGrid" functions and decide which function can be used for that

}
/*bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* pr = dynamic_cast<Ladder*>(newObj);
		if (pr != NULL)
		{
			int vcellcurr = this->GetPosition().VCell();
			int hcellcurr = this->GetPosition().HCell();
			int vcellcurrend = this->GetEndPosition().VCell();
			int hcellcurrend = this->GetEndPosition().HCell();
			int vcellnew = pr->GetPosition().VCell();
			int hcellnew = pr->GetPosition().HCell();
			int vcellnewend = pr->GetEndPosition().VCell();
			int hcellnewend = pr->GetEndPosition().HCell();
			if (hcellcurr == hcellnew && ((vcellnew >= vcellcurr && vcellnew <= vcellcurrend) || (vcellnewend > vcellcurr && vcellnewend < vcellcurrend)))
			{
				return true;
			}
			else
				return false;
		}

}
*/
CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
