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
worm_t* allocBlankWorm()
{
    worm_t* newWorm = malloc(sizeof(worm_t));

    return newWorm;
}



void freeWorm(worm_t* aWorm)
{
    free(aWorm);
}


void initializeDefaultWorm(worm_t* aworm)
{
    setCurLastIndex(aworm, 0);
    setMaxIndex(aworm, WORM_LENGTH);
    setHeadIndex(aworm, 0);
}

void initializeWormWithValues(worm_t* aworm, pos_t startPos, colorpairs_t wcolor)
{
    setWormPos(aworm, startPos);
    setWormColor(aworm, wcolor);
}

// Setters
void setCurLastIndex(worm_t* aworm, int LastIndex)
{
    aworm -> cur_lastindex = LastIndex;
}

void setMaxIndex(worm_t* aworm, int maxindex)
{
    aworm -> maxindex = maxindex;
}

void setHeadIndex(worm_t* aworm, int headindex)
{
    aworm -> headindex = headindex;
}

void setWormPos(worm_t* aworm, pos_t wormPos)
{
    aworm -> wormpos[aworm -> headindex] = wormPos;   
}

void setNextStep(worm_t* aworm, pos_t nextStep)
{
    aworm -> nextStep = nextStep;
}

void setWormColor(worm_t* aworm, colorpairs_t wcolor)
{
    aworm -> wcolor = wcolor;
}

// Getters
extern pos_t getWormHeadPos(worm_t* aworm)
{
    // structures are passed by value!
    // -> we return a copy here
    return aworm -> wormpos[aworm -> headindex];


}

int getWormLength(worm_t* aworm)
{
    return aworm -> cur_lastindex;
}
