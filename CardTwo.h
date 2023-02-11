#pragma once
#include"Card.h"
#include"Grid.h"
class CardTwo:public Card
{

public:
	CardTwo(const CellPosition& pos); 

	virtual void Apply(Grid* pGrid, Player* pPlayer);  
	virtual void ReadCardParameters(Grid* pGrid);
	virtual ~CardTwo(); 
};

