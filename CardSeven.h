#pragma once
#include "Card.h"
#include"Grid.h"
class CardSeven : public Card
{
private:

public:
	CardSeven(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid); // No parameters
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSeven();
};

