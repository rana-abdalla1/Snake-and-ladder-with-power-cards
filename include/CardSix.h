#pragma once
#include "Card.h"
class CardSix : public Card
{

	CellPosition FinalPos;

public:
	CardSix(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is: FinalPos
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSix();
};

