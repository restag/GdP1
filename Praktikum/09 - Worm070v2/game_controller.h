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

#ifndef _GAME_CONTROLER_H
#define _GAME_CONTROLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// put defines below here
// game setting
#define NAP_TIME 100            // Time in milliseconds to sleep between updates of display


//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum ResCodes {
	RES_OK,
	RES_FAILED,
    RES_INTERNAL_ERROR,
};
/*
// Game state codes
enum GameStates {
	WORM_GAME_ONGOING,
    WORM_CRASH,         // Crashed into a barrier
	WORM_OUT_OF_BOUNDS,	// left screen
	WORM_GAME_QUIT,		// User likes to quit
    WORM_CROSSING,      // Worm bit itself
};
*/
//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum ResCodes rescodes_t;
//typedef enum GameStates gamestates_t;


//*********************************************************
//* structs
//*********************************************************
// put structs below here


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here
// run the level
//rescodes_t doLevel();


#endif  // #define _GAME_CONTROLER_H

