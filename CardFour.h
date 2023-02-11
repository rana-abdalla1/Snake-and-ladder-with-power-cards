#pragma once
#include"Card.h"

class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardFour(); // A Virtual Destructor
};

