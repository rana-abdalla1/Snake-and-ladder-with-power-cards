#pragma once
#include "Card9_11.h"
class CardTen : public Card9_11
{
	static Player* owner;
	static bool firstTime;
public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card9_11
	void Apply(Grid* pGrid, Player* pPlayer);
	int GetcardPrice();
	void changeOwner(Player* ptr);
	static void resetowner() ; //static member function that reset owner to NULL
	virtual ~CardTen(); // A Virtual Destructor
};




