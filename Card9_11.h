#pragma once
#include "Card.h"

class Card9_11 : public Card
{
protected:
	int cardPrice;
	int feesToPayByPlayers;
public:
	Card9_11(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card9_11

	virtual void Apply(Grid* pGrid, Player* pPlayer, Player*& owner);  // Applies the effect of Card9_11 on the passed Player //Owner s sent by reference so to update owner data member for each derived class
	virtual int GetcardPrice()=0; //getter for card price
	virtual void changeOwner(Player* ptr)=0; // virtual function to change owner to passed player
	virtual ~Card9_11(); // A Virtual Destructor
};

