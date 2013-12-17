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
 * The wormmodel contains the data needed for worm creation and modification
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <stdlib.h>

// put custom header includes below here
#include "worm_model.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* model allocation
worm_t* allocWorm(void)
{
    worm_t* newWorm = malloc(sizeof(worm_t));

    return newWorm;
}

pos_t* allocWormposArray(int arraypositions)
{
    pos_t* newWormposArray = malloc(arraypositions * sizeof(pos_t));

    return newWormposArray;
}

//*********************************************************
//* free model
void freeWorm(worm_t* theWorm)
{
    free(theWorm);
}

void freeWormposArray(pos_t* wormposArray)
{
    free(wormposArray);
}


//*********************************************************
//* setters


//*********************************************************
//* getters
int getWormLength(worm_t* theWorm)
{
    return theWorm -> cur_lastindex + 1;
}

pos_t getWormposAtIndex(worm_t* theWorm, int index)
{
    return theWorm -> wormpos[index];
}
