# Project Architecture Documentation

## Overview

The Snake and Ladder with Power Cards project follows a well-structured object-oriented design with clear separation of concerns. This document outlines the architectural patterns, class relationships, and design decisions implemented in the project.

## Architectural Patterns

### 1. Model-View-Controller (MVC) Pattern
- **Model**: Game logic classes (Grid, Player, GameObject, Cards)
- **View**: UI classes (Output, rendering functions)
- **Controller**: ApplicationManager, Action classes

### 2. Command Pattern
All user interactions are encapsulated as Action objects:
- **Action** (base class): Defines the interface for all actions
- **Concrete Actions**: RollDiceAction, AddCardAction, etc.
- **Invoker**: ApplicationManager executes actions
- **Benefits**: Undo/Redo capability, action logging, decoupled UI

### 3. Strategy Pattern
Card implementations use the strategy pattern:
- **Context**: Player landing on a card
- **Strategy Interface**: Card::Apply() method
- **Concrete Strategies**: CardOne, CardTwo, etc.
- **Benefits**: Easy to add new card types, flexible card effects

### 4. Factory Pattern (Implicit)
Card creation and action creation follow factory-like patterns for object instantiation based on types.

## Core Components

### ApplicationManager
- **Role**: Central controller and facade
- **Responsibilities**:
  - Manages game state transitions
  - Coordinates between UI and game logic
  - Handles action creation and execution
  - Manages the main game loop

### Grid
- **Role**: Game board representation and game state manager
- **Responsibilities**:
  - Manages the 10x11 cell grid
  - Tracks all game objects (snakes, ladders, cards)
  - Manages player positions and turns
  - Handles win/lose conditions
  - Provides interface to Input/Output systems

### GameObject Hierarchy
```
GameObject (abstract base)
├── Snake
├── Ladder
└── Card (abstract)
    ├── CardOne (wallet decrement)
    ├── CardTwo (wallet increment)
    ├── CardThree (advance steps)
    ├── CardFour (move backward)
    ├── CardFive (move to position)
    ├── CardSix (bring player here)
    ├── CardSeven (go to another player)
    ├── CardEight (freeze next player)
    ├── CardNine (go to nearest ladder)
    ├── CardTen (go to nearest snake)
    ├── CardEleven (go to nearest card)
    └── CardTwelve (return to start)
```

### Action System
```
Action (abstract base)
├── Design Mode Actions
│   ├── AddCardAction
│   ├── AddLadderAction
│   ├── AddSnakeAction
│   ├── CopyCardAction
│   ├── CutCardAction
│   ├── PasteCardAction
│   ├── DeleteGameObjectAction
│   └── SaveGridAction
└── Play Mode Actions
    ├── RollDiceAction
    ├── InputDiceValueAction
    └── NewGameAction
```

## Class Relationships

### Aggregation Relationships
- **ApplicationManager** aggregates **Grid**, **Input**, **Output**
- **Grid** aggregates **Cell[][]**, **Player[]**, **Input**, **Output**
- **Cell** aggregates **GameObject** (composition)

### Inheritance Relationships
- All cards inherit from **Card**
- All actions inherit from **Action**
- All game objects inherit from **GameObject**

### Dependency Relationships
- Actions depend on **Grid** and specific game objects
- Cards depend on **Player** and **Grid** for their effects
- UI classes depend on game logic classes for data

## Data Flow

### Game Initialization
1. ApplicationManager creates Grid, Input, Output
2. Grid initializes cell array and players
3. UI components are set up and ready

### User Action Processing
1. Input system captures user interaction
2. ApplicationManager determines ActionType
3. Appropriate Action object is created
4. Action reads parameters (if needed)
5. Action executes game logic changes
6. Output system updates display

### Game State Updates
1. Player moves trigger position updates
2. Landing on game objects triggers their effects
3. Grid checks for win conditions
4. UI reflects all state changes

## Key Design Decisions

### 1. Separation of Header and Source Files
- **Headers** (`include/`): Interface definitions, declarations
- **Sources** (`src/`): Implementation details
- **Benefits**: Faster compilation, clear interfaces, reduced dependencies

### 2. Modular File Organization
```
src/
├── Core/          # Essential game logic
├── GameObjects/   # Game entities and cards
├── Actions/       # User interaction handlers  
└── UI/           # Input/Output handling
```

### 3. Parameter Validation
- All user inputs are validated at the point of entry
- Cards validate their parameters during creation
- Error messages guide users to correct inputs

### 4. State Management
- Grid maintains authoritative game state
- Players track their own position and wallet
- Actions are stateless and operate on external state

## Extension Points

### Adding New Cards
1. Create new card class inheriting from Card
2. Implement ReadCardParameters() and Apply() methods
3. Add card type to relevant enums
4. Update action handlers for card creation

### Adding New Actions
1. Create new action class inheriting from Action
2. Implement ReadActionParameters() and Execute() methods
3. Add action type to ActionType enum
4. Update ApplicationManager to handle new action

### Modifying Game Rules
- Board size: Modify constants in UI_Info.h
- Player count: Adjust MaxPlayerCount in definitions
- Wallet system: Modify Player class wallet methods
- Win conditions: Update Grid's end-game logic

## Testing Strategy

### Unit Testing
- Individual card effects
- Player movement calculations
- Action parameter validation
- Game state transitions

### Integration Testing
- Complete game scenarios
- Mode switching (Design ↔ Play)
- File save/load operations
- Multi-player turn management

### User Acceptance Testing
- Complete gameplay sessions
- Design mode functionality
- Error handling and recovery
- Performance with full boards

## Performance Considerations

### Memory Management
- Dynamic allocation for game objects
- Proper cleanup in destructors
- Avoiding memory leaks in action execution

### Rendering Optimization
- Only update changed areas of display
- Efficient graphics library usage
- Minimal redraws during gameplay

### Algorithm Efficiency
- O(1) cell access via 2D array
- Efficient player movement calculations
- Optimized nearest-object searches for cards

## Future Enhancements

### Potential Additions
1. **Network Multiplayer**: Remote player support
2. **AI Players**: Computer-controlled opponents
3. **Custom Themes**: Different visual styles
4. **Statistics Tracking**: Player performance metrics
5. **Advanced Cards**: More complex card effects
6. **Tournaments**: Multi-game competitions
7. **Mobile Version**: Touch-optimized interface

### Architectural Improvements
1. **Event System**: Pub-sub for loose coupling
2. **Configuration Files**: External game settings
3. **Plugin Architecture**: Dynamic card loading
4. **Scripting Support**: Custom card behaviors
5. **Database Integration**: Persistent player data

This architecture provides a solid foundation for the current game while remaining flexible enough to accommodate future enhancements and modifications.
