
/**
 * @file Main.cpp
 * @brief Entry point for the Snake and Ladder with Power Cards game
 * 
 * This file contains the main function that initializes and runs the game loop.
 * The main function handles the core game cycle of reading user input,
 * executing actions, and updating the display.
 * 
 * @author Game Development Team
 * @date 2025
 */

#include "../../include/ApplicationManager.h"

/**
 * @brief Main function - Entry point of the Snake and Ladder game
 * 
 * This function creates an ApplicationManager instance and runs the main game loop.
 * The loop continues until the user chooses to exit the application.
 * 
 * Game Loop Process:
 * 1. Read user action from input (mouse clicks, keyboard input)
 * 2. Execute the corresponding action (move player, add objects, etc.)
 * 3. Update the user interface to reflect changes
 * 4. Repeat until EXIT action is triggered
 * 
 * @return int Exit status (0 for successful termination)
 * 
 * @note This Main Function Must NOT be Changed (as per project requirements)
 */
int main()
{
	ActionType ActType; // Variable to store the current user action

	// Create an object of ApplicationManager - the central controller
	// This manages the game state, UI, and coordinates all components
	ApplicationManager AppManager;

	// Main game loop - continues until user chooses to exit
	do
	{		
		// Read user action from input system (mouse clicks, keyboard)
		// Returns an ActionType enum representing what the user wants to do
		ActType = AppManager.GetUserAction();

		// Execute the action based on user input
		// This could be rolling dice, adding game objects, switching modes, etc.
		AppManager.ExecuteAction(ActType);

		// Update the drawings of the window after executing the action
		// Redraws the game board, players, and UI elements to show current state
		AppManager.UpdateInterface();

	} while(ActType != EXIT); // Continue until user chooses to exit

	return 0; // Successful program termination
}


