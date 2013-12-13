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

//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <stdlib.h>

// put custom header includes below here
#include "worm_model.h"
#include "board_model.h"

//*********************************************************
//* global vars
//*********************************************************



//*********************************************************
//* fuctions
//*********************************************************
// allocating & freeing
worm_t* allocWorm(void)
{
    worm_t* newWorm = malloc(sizeof(worm_t));

    return newWorm;
}

void freeWorm(worm_t* theWorm)
{
    free(theWorm);
}


// Setters
void setCurLastIndex(worm_t* theWorm, int lastindex)
{
    theWorm -> cur_lastindex = lastindex;
}

void setMaxIndex(worm_t* theWorm, int maxindex)
{
    theWorm -> maxindex = maxindex;
}

void setHeadIndex(worm_t* theWorm, int headindex)
{
    theWorm -> headindex = headindex;
}

void setWormpos(worm_t* theWorm, pos_t wormpos)
{
    theWorm -> wormpos[theWorm -> headindex] = wormpos;   
}

void setNextStep(worm_t* theWorm, pos_t nextStep)
{
    theWorm -> nextStep = nextStep;
}

void setWormColor(worm_t* theWorm, colorpairs_t wcolor)
{
    theWorm -> wcolor = wcolor;
}


// Getters
extern pos_t getWormHeadPos(worm_t* theWorm)
{
    // structures are passed by value!
    // -> we return a copy here
    return theWorm -> wormpos[theWorm -> headindex];


}

int getWormLength(worm_t* theWorm)
{
    return theWorm -> cur_lastindex;
}
