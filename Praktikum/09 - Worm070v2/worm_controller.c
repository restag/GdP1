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


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
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


//*********************************************************
//* free module


//*********************************************************
//* module management


//*********************************************************
//* module content management
pos_t getWormHeadpos(worm_t* theWorm)
{
    // structures are passed by value!
    // -> we return a copy here
    return getWormposAtIndex(theWorm, getHeadindex(theWorm));


}

//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
