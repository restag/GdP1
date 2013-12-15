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
 * The boardcontroller is used for boar interaction
 *
 * Tasks:
 *      * initialization
 *      * handling
 */


#ifndef _BOARD_CONTROLLER_H
#define _BOARD_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_model.h"
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
board_t* initializeBoard(void);
void initializeBarriers(board_t* aBoard);

//* free module

//* module management

//* module content management
void placeItem(board_t* aBoard, pos_t position, char symbol, boardcodes_t boardcode, colorpairs_t color);

//* output management

//* display management

//* display interaction
void printItem(pos_t position, char symbol, colorpairs_t color);

#endif  // #define _BOARD_CONTROLLER_H
