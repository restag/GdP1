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
#include "game_model.h"
#include "display_controller.h"

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
worm_t* initializeWorm(board_t* aBoard, pos_t startPos, wormheading_t dir, colorpairs_t);
worm_t* initializeUserWorm(board_t* aBoard);
//* free module

//* module management
void moveWorm(board_t* aBoard, worm_t* aWorm, gamestates_t* aGamestate);
void growWorm(worm_t* aWorm, bonus_t growth);

//* module content management
pos_t getWormHeadpos(worm_t* aWorm);
pos_t getWormTailpos(worm_t* aWorm);
void setWormHeading(worm_t* aWorm, wormheading_t dir);
void cleanWormTail(board_t* aBoard, worm_t* aWorm);
void incrementWormindex(int index);
//* output management

//* display management

//* display interaction
void showWorm(board_t* aBoard, worm_t* aWorm);

#endif  // #define _<MODULE-NAME>_CONTROLLER_H
