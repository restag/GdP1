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
 * The userinteractioncontroller is used for user interaction
 *
 * Tasks:
 *      * reading the keyboard input
 *
 */


#ifndef _USERINTERACTION_CONTROLLER_H
#define _USERINTERACTION_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_model.h"
#include "game_controller.h"

//*********************************************************
//* defines
//*********************************************************
// put defines below here


//*********************************************************
//* enums
//*********************************************************
// put enums below here


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here


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

//* free module

//* module management

//* module content management

//* input management
void readUserInput(worm_t* aWorm, gamestates_t* agame_state);

//* display management

//* display interaction

#endif  // #define _USERINTERACTION_CONTROLLER_H
