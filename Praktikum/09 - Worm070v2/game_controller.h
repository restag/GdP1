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
 * Tasks:
 *      * Level initialization
 *      * run game
 *
 */


#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_model.h"


//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define NAP_TIME 100

//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum ResCodes {
    RES_OK,
    RES_FAILED,
    RES_INTERNAL_ERROR,
};

enum GameStates {
    WORM_CRASH,             // crashed into barrier
    WORM_CROSSING,          // worm bit itself
    WORM_GAME_ONGOING,      // all good
    WORM_GAME_QUIT,         // user likes to quit
    WORM_OUT_OF_BOUNDS,     // left gameboard
};

//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum ResCodes rescodes_t;
typedef enum GameStates gamestates_t;

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

//* initialize module
void initializeLevel(board_t* aBoard);


//* free module

//* module management

//* module content management

//* output management

//* display management

//* display interaction

#endif  // #define _GAME_CONTROLLER_H
