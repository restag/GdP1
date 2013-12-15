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
 * The wormcontroller is used for worm interaction
 *
 * Tasks:
 *      * initialization
 *      * movement
 */


#ifndef _WORM_CONTROLLER_H
#define _WORM_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_model.h"
#include "board_model.h"

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
pos_t getWormHeadpos(worm_t* aWorm);

//* output management

//* display management

//* display interaction

#endif  // #define _<MODULE-NAME>_CONTROLLER_H
