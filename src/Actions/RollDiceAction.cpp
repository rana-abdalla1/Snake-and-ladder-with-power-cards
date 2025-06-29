/**
 * @file RollDiceAction.cpp
 * @brief Implementation of RollDiceAction class for handling dice rolling in gameplay
 * 
 * This action is responsible for generating random dice values, moving players,
 * handling special card effects, and managing turn progression during the game.
 * It's one of the core gameplay actions in Play Mode.
 * 
 * @author Game Development Team
 * @date 2025
 */

#include "..\..\include\RollDiceAction.h"
#include "..\..\include\Grid.h"
#include "..\..\include\Player.h"

#include <time.h> // used in srand to generate random numbers with different seed

/**
 * @brief Constructor for RollDiceAction
 * 
 * Initializes the RollDiceAction with a reference to the ApplicationManager.
 * This action doesn't require any parameters from the user.
 * 
 * @param pApp Pointer to the ApplicationManager for accessing game components
 */
RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

/**
 * @brief Reads action parameters from user input
 * 
 * RollDiceAction doesn't require any parameters from the user as the dice
 * value is generated randomly. This function is kept for interface compliance
 * but performs no operations.
 */
void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user - dice value is generated randomly
}

/**
 * @brief Executes the dice rolling action and handles player movement
 * 
 * This function implements the complete dice rolling sequence:
 * 1. Checks if the game has ended
 * 2. Generates a random dice value (1-6)
 * 3. Handles player freeze status (from Card 8 effect)
 * 4. Moves the current player based on dice value
 * 5. Handles special movement effects (like Card 5 backward movement)
 * 6. Advances to the next player's turn
 * 
 * Game State Checks:
 * - Verifies game hasn't ended before allowing dice roll
 * - Checks if current player is frozen (skips turn if frozen)
 * - Handles special card effects that modify movement
 */
void RollDiceAction::Execute()
{
	// Get pointer to the game grid for accessing game state
	Grid* pGrid = pManager->GetGrid();
	
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		// Game has ended, prevent further dice rolling
		pGrid->PrintErrorMessage("Game Already Ended, Cannot roll dice.");
	}
	// -- If not ended, do the following --:
	else
	{
		// 2- Generate a random number from 1 to 6
		srand((int)time(NULL)); // Initialize random seed with current time for different results each run
		int diceNumber = 1 + rand() % 6; // Generate random number from 1 to 6
		
		// 3- Get the "current" player from pGrid
		Player* currplayer = pGrid->GetCurrentPlayer();
		
		// Check if player is frozen (affected by Card 8 - skip turn effect)
		if (currplayer->GetFreeze() > 0) //if player is frozen and cannot move this turn
		{
			// Player is frozen, skip their turn
			currplayer->IncrementTurn(); //Will go to the next turn and reset freeze counter to 0
			pGrid->PrintErrorMessage("You cannot roll dice this turn, click to proceed to next player");
			pGrid->AdvanceCurrentPlayer(); //Advance to the next player
			return; // Exit early, no movement this turn
		}

		// 4- Move the currentPlayer using the Move function of Player class
		currplayer->Move(pGrid, diceNumber);
		
		// Handle special backward movement effect (Card 5 effect)
		if (currplayer->GetmovingBack() == 1)
		{
			// Player landed on Card 5, which causes backward movement
			pGrid->PrintErrorMessage("You landed on card 5! You will move backward, click to continue");
			currplayer->MoveBackward(pGrid, diceNumber);
			currplayer->SetmovingBack(0); // Reset the backward movement flag
		}
		
		// 5- Advance the current player number of pGrid to next player's turn
		pGrid->AdvanceCurrentPlayer();
	}
}

/**
 * @brief Destructor for RollDiceAction
 * 
 * Performs cleanup for RollDiceAction objects. Currently no special cleanup
 * is required as the base class handles standard cleanup operations.
 */
RollDiceAction::~RollDiceAction()
{
}
