/* A simple variant of the game Snake
 * Used for teaching in classes
 *
 * This version is an alternativ version of the given code,
 * following a more strict approach of separation
 *
 *
 * Author:
 * Benjamin Ewert
 * (c) 2013
 *
 * Author of original version:
 * Franz Regensburger
 * Ingolstadt University of Applied Sciences
 * (C) 2011
 *
 */

#ifndef _GAMEOPS_H
#define _GAMEOPS_H
//*********************************************************
//* header includes 
//*********************************************************
//none

//* type definitions
//*********************************************************
// Result codes of functions
typedef enum ResCodes {
	RES_OK,
	RES_FAILED,
} rescodes_t;

// Game state codes
typedef enum GameStates {
	WORM_GAME_ONGOING,
	WORM_OUT_OF_BOUNDS,	// left screen
	WORM_GAME_QUIT,		// User likes to quit
    WORM_CROSSING,      // Worm bit itself
} gamestates_t;


//*********************************************************



//*********************************************************
//* defines
//*********************************************************
// game setting
#define NAP_TIME 100            // Time in milliseconds to sleep between updates of display


//*********************************************************
//* function prototypes
//*********************************************************
rescodes_t doLevel();


#endif  // #define _GAMEOPS_H
