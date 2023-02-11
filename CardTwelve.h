#pragma once
#include "Card.h"
#include "Card9_11.h"
class CardTwelve : public Card
{

public:
	CardTwelve(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardTwelve();
};

