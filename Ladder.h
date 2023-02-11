#pragma once

#include "GameObject.h"
#include <fstream>
class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	static int ladderscount;
	static bool saved;
	CellPosition endCellPos; // here is the ladder's End Cell Position

public:
	void setType(enum t);
	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	//virtual bool IsOverlapping(GameObject*newObj) const;

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	void Save(ofstream& Outfile, Type t);
	int getLaddersCount();
	virtual ~Ladder(); // Virtual destructor
};

