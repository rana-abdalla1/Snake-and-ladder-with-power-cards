#pragma once
#include"Card.h"

class CardFive : public Card
{

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardFive(); // A Virtual Destructor
};

