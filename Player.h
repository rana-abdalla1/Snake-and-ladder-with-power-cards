#pragma once

#include "Grid.h"
#include "Cell.h"
class Card9_11;
class Player
{
	Cell* pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
						   // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
						   // and reset again when reached 3
						   // it is used to indicate when to move and when to add to your wallet
	int freeze; //This indicates whether the player is frozen for a turn due to card 4
	int movingBack; //This indicates that Card 5 is active on player 
	Card9_11* ownedcities[3];
	int countcities;
public:

	Player(Cell* pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell* cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet
	void SetStepCount(int stepCount);
	int GetTurnCount() const;		// A getter for the turnCount

	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid* pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
												// and Applies the Game Object's effect (if any) of the end reached cell 
												// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string& playersInfo) const; // Appends player's info to the input string, 
													   // for example: P0(wallet, turnCount)
	void IncrementTurn();
	void SetFreeze(int freeze); //function to set freeze
	int GetFreeze()  const;
	int GetmovingBack()const;
	void SetmovingBack(int movingBack);
	void MoveBackward(Grid* pGrid, int diceNumber); //Moves the player backward
	Player* GetPoor(Player* p2); //Get the player with least coin
	Card9_11* changeOwnerships(Player* p1, Grid* pGrid); //change ownership
	void AddCity(Card9_11* city);
	void resetplayers(Grid*pGrid);
	void decrementWallet(int walletamount);
	bool Move_apply(Grid* pGrid);
	bool Moveapply(Grid* pGrid,CellPosition pos);
	Player* getClosestPlayer(Player**p1,int count);
};

