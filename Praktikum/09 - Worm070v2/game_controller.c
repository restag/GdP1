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


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "game_controller.h"
#include "board_controller.h"
#include "worm_controller.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initialize module
void initializeLevel(board_t* theBoard)
{
    // initialize barriers
    initializeBarriers(theBoard);

    // initialize userworm
    initializeUserWorm(theBoard);
}

//*********************************************************
//* free module


//*********************************************************
//* module management


//*********************************************************
//* module content management


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
