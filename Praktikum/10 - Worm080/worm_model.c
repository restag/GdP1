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

pos_t* allocWormposArray(worm_t* theWorm)
{
    pos_t* newWormposArray;
    if (getWormLength(theWorm) > 0){
        newWormposArray = malloc(getWormLength(theWorm) * sizeof(pos_t));
    } else {
        newWormposArray = NULL;
    }

    return newWormposArray;
}

worm_t* resizeWormposArray(worm_t* theWorm, int newLength)
{
    worm_t* newArray = realloc(getWormposArray(theWorm), newLength * sizeof(pos_t));

    return newArray;
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
void setWormMaxindex(worm_t* theWorm, int maxindex)
{
    theWorm -> maxindex = maxindex;
}

void setWormHeadindex(worm_t* theWorm, int headindex)
{
    theWorm -> headindex = headindex;
}

void setWormposAtIndex(worm_t* theWorm, pos_t theWormpos, int index)
{
    theWorm -> wormpos[index] = theWormpos;
}

void setWormNextStep(worm_t* theWorm, pos_t* theWormpos)
{
    theWorm -> nextStep = *theWormpos;
}

void setWormcolor(worm_t* theWorm, colorpairs_t theColor)
{
    theWorm -> wcolor = theColor;
}

//*********************************************************
//* getters
int getWormMaxindex(worm_t* theWorm)
{    
    return theWorm -> maxindex;
}

int getWormLength(worm_t* theWorm)
{
    return getWormMaxindex(theWorm) + 1;
}

int getWormHeadindex(worm_t* theWorm)
{
    return theWorm -> headindex;
}

pos_t* getWormposArray(worm_t* theWorm)
{
    return theWorm -> wormpos;
}

pos_t* getWormposAtIndex(worm_t* theWorm, int index)
{
    return &theWorm -> wormpos[index];
}

pos_t* getWormNextStep(worm_t* theWorm)
{
    return &theWorm -> nextStep;
}

colorpairs_t getWormColor(worm_t* theWorm)
{
    return theWorm -> wcolor;
}
