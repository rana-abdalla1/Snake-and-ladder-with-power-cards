/**
 * @file CardOne.cpp
 * @brief Implementation of CardOne class - Wallet Decrement Card
 * 
 * CardOne is a power card that decreases a player's wallet by a specified amount
 * when the player lands on it. This card adds a financial penalty element to the game.
 * 
 * Card Effect: Decrements the player's wallet by a configurable amount
 * Parameters: walletAmount (the amount to subtract from player's wallet)
 * 
 * @author Game Development Team
 * @date 2025
 */

#include "..\..\..\include\CardOne.h"

/**
 * @brief Constructor for CardOne
 * 
 * Initializes a CardOne instance at the specified cell position and sets
 * the card number to 1. The wallet amount parameter will be set later
 * through ReadCardParameters().
 * 
 * @param pos The cell position where this card will be placed on the grid
 */
CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

/**
 * @brief Destructor for CardOne
 * 
 * Performs cleanup for CardOne objects. Currently no special cleanup is needed
 * as the base class handles the standard cleanup operations.
 */
CardOne::~CardOne(void)
{
}

/**
 * @brief Reads and validates the wallet amount parameter from user input
 * 
 * This function prompts the user to enter the amount that should be decremented
 * from a player's wallet when they land on this card. It validates the input
 * to ensure only positive values are accepted.
 * 
 * @param pGrid Pointer to the game grid for accessing input/output interfaces
 * 
 * Input Validation:
 * - Only positive integers are accepted
 * - User is re-prompted if negative values are entered
 * - Status bar is cleared after successful input
 */
void CardOne::ReadCardParameters(Grid* pGrid)
{
	// Display prompt message to user for entering wallet decrement amount
	pGrid->GetOutput()->PrintMessage("New CardOne: Enter its wallet amount");
	
	// Read the wallet decrement amount from user input
	int decrementprice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	
	// Validate input - ensure only positive values are accepted
	while (decrementprice < 0)
	{
		pGrid->PrintErrorMessage("Please enter a positive value, click to continue");
		decrementprice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	}
	
	// Store the validated wallet amount
	walletAmount = decrementprice;
	
	// Clear the status bar after successful parameter input
	pGrid->GetOutput()->ClearStatusBar();
}

/**
 * @brief Applies the CardOne effect to the specified player
 * 
 * When a player lands on CardOne, this function is called to execute the card's effect.
 * It decrements the player's wallet by the specified amount and displays an appropriate
 * message to inform the player of the wallet change.
 * 
 * @param pGrid Pointer to the game grid for accessing UI and game state
 * @param pPlayer Pointer to the player who landed on this card
 * 
 * Card Effect Process:
 * 1. Calls base class Apply() to show standard card message
 * 2. Decrements player's wallet by the stored walletAmount
 * 3. Displays confirmation message showing the amount deducted
 */
void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->decrementWallet(walletAmount);
	
	// Display message to inform player about the wallet decrement
	pGrid->PrintErrorMessage("Your wallet will be decremented by " + to_string(walletAmount) + " click to continue..");
}
