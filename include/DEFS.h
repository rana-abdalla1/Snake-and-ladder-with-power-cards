/**
 * @file DEFS.h
 * @brief Global definitions and constants for Snake and Ladder game
 * 
 * This header file contains all the global constants, enumerations, and type definitions
 * used throughout the Snake and Ladder with Power Cards project. It serves as a central
 * location for shared definitions to maintain consistency across all modules.
 * 
 * @author Game Development Team
 * @date 2025
 */

#ifndef DEFS_H
#define DEFS_H

#include "..\lib\CMUgraphicsLib\CMUgraphics.h"

/**
 * @brief Enumeration of all possible user actions in the game
 * 
 * This enum defines all the actions that users can perform in both Design Mode
 * and Play Mode. Each action corresponds to a specific user interface element
 * or user input that triggers game functionality.
 */
enum ActionType // The actions supported (add more as needed)
{
	// ========== [1] Design Mode Actions ==========
	// These actions are available when the game is in design/edit mode
	
	ADD_LADDER,				///< Add a ladder to the game board
	ADD_SNAKE,				///< Add a snake to the game board
	ADD_CARD,				///< Add a power card to the game board
	COPY_CARD,				///< Copy an existing card for duplication
	CUT_CARD,				///< Cut a card (move operation)
	PASTE_CARD,				///< Paste a previously copied/cut card
	DELETE_GAME_OBJECT,		///< Remove a game object from the board
	SAVE_GRID,				///< Save current board configuration to file
	OPEN_GRID,				///< Load a board configuration from file
	SWITCH_TO_PLAY_MODE,	///< Switch from Design Mode to Play Mode
	EXIT,					///< Exit the application

	///TODO: Add more action types of Design Mode

	// ========== [2] Play Mode Actions ==========
	// These actions are available during actual gameplay
	
	ROLL_DICE,				///< Roll dice to move player
	INPUT_DICE_VALUE,		///< Manually input dice value (for testing)
	NEW_GAME,				///< Start a new game session
	SWITCH_TO_DESIGN_MODE,	///< Switch from Play Mode to Design Mode

	///TODO: Add more action types of Play Mode

	// ========== [3] Interface Actions ==========
	// These represent different areas of the user interface
	
	EMPTY,					///< Empty area in toolbar (no action)
	GRID_AREA,				///< Click inside the game grid area
	STATUS 					///< Click inside the status bar area
};

/**
 * @brief Enumeration of game object types for serialization
 * 
 * This enum is used to identify different types of game objects when saving
 * and loading game configurations. It helps the system determine how to
 * reconstruct objects from saved data.
 */
enum Type // Type to help in saving grid
{
	LADDER,		///< Ladder game object
	SNAKE,		///< Snake game object
	CARD,		///< Generic card object
	CARD1,		///< Specific card type 1 (wallet decrease)
	CARD2,		///< Specific card type 2 (wallet increase)
	CARD3,		///< Specific card type 3 (advance player)
	CARD4,		///< Specific card type 4 (move back)
	CARD5,		///< Specific card type 5 (move to position)
	// Note: Additional card types (CARD6-CARD12) can be added here
};

#endif // DEFS_H