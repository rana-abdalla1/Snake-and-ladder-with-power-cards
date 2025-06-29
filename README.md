# Snake and Ladder Game with Power Cards

A C++ implementation of the classic Snake and Ladder board game enhanced with special power cards that add strategic elements and excitement to the gameplay.

## 🎮 Game Overview

This project is a digital version of the traditional Snake and Ladder game with additional power cards that provide special abilities and effects. Players roll dice to move across a 10x11 grid board, encountering snakes that take them down, ladders that help them climb up, and power cards that trigger various effects.

## ✨ Features

### Core Gameplay
- **Classic Snake and Ladder mechanics**: Navigate through a 10x11 grid board
- **Multiple players support**: Up to 4 players can play simultaneously
- **Interactive GUI**: User-friendly graphical interface built with CMU Graphics Library
- **Dice rolling system**: Random dice values or manual input for testing

### Power Cards System
The game includes 12 different power cards, each with unique effects:

1. **Card 1**: Decreases player's wallet by a specified amount
2. **Card 2**: Increases player's wallet by a specified amount  
3. **Card 3**: Advances player by a specified number of steps
4. **Card 4**: Moves player back by a specified number of steps
5. **Card 5**: Moves player to a specific cell position
6. **Card 6**: Moves another player to current player's position
7. **Card 7**: Moves current player to another player's position
8. **Card 8**: Prevents next player from rolling dice (skip turn)
9. **Card 9**: Moves player to the nearest ladder in the same column
10. **Card 10**: Moves player to the nearest snake in the same column
11. **Card 11**: Moves player to the nearest card in the same column
12. **Card 12**: Returns player to starting position

### Game Modes
- **Design Mode**: Create and edit game boards
  - Add/remove snakes, ladders, and cards
  - Copy, cut, and paste cards
  - Save and load custom board configurations
- **Play Mode**: Experience the gameplay
  - Roll dice and move players
  - Trigger card effects
  - Track player wallets and positions

## 📁 Project Structure

```
Snake-and-ladder-with-power-cards/
├── src/                          # Source code files
│   ├── Core/                     # Core game logic
│   │   ├── Main.cpp             # Application entry point
│   │   └── Player.cpp           # Player class implementation
│   ├── GameObjects/             # Game entities
│   │   ├── Cards/               # Power card implementations
│   │   │   ├── Card.cpp         # Base card class
│   │   │   ├── CardOne.cpp      # Individual card implementations
│   │   │   ├── CardTwo.cpp
│   │   │   └── ...              # Cards 3-12
│   │   ├── GameObject.cpp       # Base game object class
│   │   ├── Ladder.cpp           # Ladder implementation
│   │   └── Snake.cpp            # Snake implementation
│   ├── Actions/                 # User action handlers
│   │   ├── AddCardAction.cpp    # Add card to board
│   │   ├── AddLadderAction.cpp  # Add ladder to board
│   │   ├── AddSnakeAction.cpp   # Add snake to board
│   │   ├── RollDiceAction.cpp   # Dice rolling logic
│   │   └── ...                  # Other game actions
│   └── UI/                      # User interface
│       ├── Input.cpp            # Input handling
│       └── Output.cpp           # Graphics and display
├── include/                     # Header files
│   ├── DEFS.h                   # Global definitions and enums
│   ├── UI_Info.h                # UI configuration constants
│   └── ...                      # All header files
├── lib/                         # External libraries
│   └── CMUgraphicsLib/          # CMU Graphics Library
├── assets/                      # Game resources
│   └── images/                  # Game images and sprites
├── build/                       # Build files and project configuration
│   ├── Debug/                   # Debug build outputs
│   └── PT-Project.*             # Visual Studio project files
├── tests/                       # Test files and configurations
├── docs/                        # Documentation
└── README.md                    # This file
```

## 🛠️ Technologies Used

- **Language**: C++
- **Graphics**: CMU Graphics Library
- **IDE**: Visual Studio
- **Build System**: Visual Studio Project (.vcxproj)


## 🎯 How to Play

### Design Mode
1. **Adding Game Objects**:
   - Click on Snake, Ladder, or Card icons in the toolbar
   - Click on the desired cell to place the object
   - For cards, specify additional parameters when prompted

2. **Managing Objects**:
   - Use Copy/Cut/Paste to duplicate cards
   - Delete objects by selecting the delete tool and clicking on them
   - Save your custom board layout

### Play Mode
1. **Starting the Game**:
   - Switch to Play Mode from the toolbar
   - Players take turns automatically

2. **Taking Turns**:
   - Click "Roll Dice" to move your player
   - Land on cards to trigger their effects
   - Use ladders to climb up, avoid snakes that take you down
   - First player to reach the final cell wins!

## 🔧 Configuration

### Game Settings
- **Grid Size**: 10 columns × 11 rows (configurable in UI_Info.h)
- **Player Count**: Up to 4 players (configurable in DEFS.h)
- **Wallet System**: Players start with a default wallet amount

### Customization
- Modify card effects by editing individual card class implementations
- Adjust UI colors and layout in the UI configuration files
- Add new card types by extending the Card base class

## 🏗️ Architecture

### Design Patterns Used
- **Strategy Pattern**: Different card types implement the same interface
- **Command Pattern**: Actions are encapsulated as command objects
- **Singleton Pattern**: ApplicationManager manages the game state
- **Observer Pattern**: UI updates based on game state changes

### Key Classes
- **ApplicationManager**: Central controller managing the game flow
- **Grid**: Represents the game board and manages cells
- **Player**: Represents individual players with position and wallet
- **Card**: Abstract base class for all power cards
- **GameObject**: Base class for all board objects (snakes, ladders, cards)
- **Action**: Base class for all user actions


---

**Enjoy playing Snake and Ladder with Power Cards!** 🎲🐍🪜
