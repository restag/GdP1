// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//

#ifndef _WORM_H
#define _WORM_H

// Result codes of functions
typedef enum ResCodes {
	RES_OK,
	RES_FAILED,
} rescodes_t;

// Dimensions and bounds
#define NAP_TIME 100            // Time in milliseconds to sleep between updates of display
#define WORM_LENGTH 20          // Maximal length of the worm

// Codes for the array of positions
#define UNUSED_POS_ELEM -1      // Unused element in the worm arrays of positions

// Symbols to display
#define SYMBOL_FREE_CELL ' '
#define SYMBOL_WORM_INNER_ELEMENT '0'

// Game state codes
typedef enum GameStates {
	WORM_GAME_ONGOING,
	WORM_OUT_OF_BOUNDS,	// left screen
	WORM_GAME_QUIT,		// User likes to quit
    WORM_CROSSING,      // worm bit itself
} gamestates_t;

#endif  // #define _WORM_H
