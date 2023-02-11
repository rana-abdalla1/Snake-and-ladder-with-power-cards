#include "Player.h"

#include "GameObject.h"
#include "Card9_11.h"
#include "Ladder.h"
Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	if (pCell->GetCellPosition().IsValidCell())//making sure passed cell pointer is of a valid cell SSSSS
		this->pCell = pCell;
	this->turnCount = 0;
	freeze = 0;
	movingBack = 0;
	for (int i = 0;i < 3;i++)
	{
		ownedcities[i] = NULL;
	}
	countcities = 0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet > 0)
		this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetStepCount(int stepCount)
{
	this->stepCount = stepCount;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);//draws player using draw player function SSSS

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);//TELL HUSSEIN TO SET BRUSH TO"CELL COLOR"

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	stepCount += diceNumber;
	turnCount = turnCount + 1;

	if (turnCount == 3)
	{
		turnCount = 0;
		stepCount -= diceNumber;
		if (freeze > 0)
			return;
		wallet = wallet + (diceNumber * 10);
		return;
	}
	if (wallet == 0)
	{
		pGrid->PrintErrorMessage("You must have at least 1 coin to move");
		return;
	}
	justRolledDiceNum = diceNumber;
	int newCellNum = CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) + diceNumber; // Called using classname
	if (newCellNum > 99)
		newCellNum = 99;
	CellPosition pos = CellPosition::GetCellPositionFromNum(newCellNum);
	pGrid->UpdatePlayerCell(this, pos);
	GameObject* obj = pCell->GetGameObject();
	if (obj != NULL)
	{
		obj->Apply(pGrid, this);//consider putting inside update player cell to ensure that multiple applies can occur
	}
	//apply game object here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (newCellNum == 99)
	{
		pGrid->SetEndGame(true);
	}

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

}
void Player::MoveBackward(Grid* pGrid, int diceNumber)
{
	int newCellNum = CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) + (diceNumber * -1); // Called using classname
	if (newCellNum < 1)
		newCellNum = 1;
	CellPosition pos = CellPosition::GetCellPositionFromNum(newCellNum);
	pGrid->UpdatePlayerCell(this, pos);
	GameObject* obj = pCell->GetGameObject();
	if (obj!=NULL)
	{
		obj->Apply(pGrid, this);
	}
}
void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::IncrementTurn()
{
	turnCount++;
	if (turnCount == 3)
	{
		turnCount = 0;
	}
	freeze--;
}
void Player::SetFreeze(int freeze)
{
	this->freeze = freeze;
}
int Player::GetFreeze() const
{
	return freeze;
}
void Player::SetmovingBack(int movingBack)
{
	this->movingBack = movingBack;
}
int Player::GetmovingBack() const
{
	return movingBack;
}
Player* Player::GetPoor(Player* p2)
{
	if (wallet > (p2->wallet))
		return p2;
	else
		return this;
}
Card9_11* Player::changeOwnerships(Player* p1, Grid* pGrid)
{

	Card9_11* tempptr = NULL;
	int price = -1;
	int mostexpensiveindex = 0;
	for (int i = 0;i < 3;i++)
	{
		if (ownedcities[i] != NULL && ownedcities[i]->GetcardPrice() > price)
		{
			price = ownedcities[i]->GetcardPrice();
			tempptr = ownedcities[i];
			mostexpensiveindex = i;
		}
	}

	if (tempptr != NULL)
	{
		pGrid->PrintErrorMessage("Most expensive city of current player will be given to poorest player, click to continue");
		p1->ownedcities[mostexpensiveindex] = tempptr;//ownership moved to passed player
		ownedcities[mostexpensiveindex] = NULL; //Drops the most expensive city to current player
		countcities--;
		p1->countcities++;
	}
	else
	{
		pGrid->PrintErrorMessage("No exchange of cities, current player has no cities to exchange, click to continue");

	}
	return tempptr;

}
void Player::AddCity(Card9_11* city)
{
	ownedcities[countcities] = city;
	countcities++;
}

void Player::resetplayers(Grid* pGrid)
{
	stepCount = 1;
	wallet = 100;
	turnCount = 0;
	freeze = 0;
	movingBack = 0;
	countcities = 0;
	for (int i = 0;i < 3;i++)
	{
		ownedcities[i] = NULL;
	}
	CellPosition temp(8, 0);
	pGrid->UpdatePlayerCell(this, temp);
}

void Player::decrementWallet(int walletamount)
{
	if (wallet >= walletamount)
		wallet -= walletamount;
	else
		wallet = 0; //will make player's wallet 0 if he has no enough coins
}
bool Player::Moveapply(Grid* pGrid,CellPosition pos)
{
	pGrid->UpdatePlayerCell(this,pos);
	GameObject* obj = pCell->GetGameObject();
	if (obj != NULL)
	{
		obj->Apply(pGrid, this);
		return true;
	}
	else
	{
		return false;
	}

}
bool Player::Move_apply(Grid* pGrid)
{
	CellPosition pos = pCell->GetCellPosition();
	Ladder* pLadder = pGrid->GetNextLadder(pos);
	if (pLadder != NULL)
	{
		CellPosition nextLadderpos = pLadder->GetPosition();
		pGrid->UpdatePlayerCell(this, nextLadderpos);
		GameObject* obj = pCell->GetGameObject();
		if (obj!=NULL)
		{
			obj->Apply(pGrid, this);
		}
		return true;
	}
	else
	{
		return false;
	}
}

Player* Player::getClosestPlayer(Player** p1,int count)
{
	int temp = 100;
	Player* closest = NULL;
	for (int i = 0;i < count;i++)
	{
		int distance = p1[i]->stepCount-(this->stepCount);
		if (distance > 0 && distance < temp)
		{
			closest = p1[i];
			temp = distance;
		}
	}
	return closest;
}


