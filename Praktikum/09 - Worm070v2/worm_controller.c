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
#include "board_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initialize module
worm_t* initializeWorm(board_t* theBoard, pos_t startPos, wormheading_t dir, colorpairs_t color)
{
    // reserve memory
    worm_t* newWorm = allocWorm();

    // set default values
    setWormLength(newWorm, 4);
    setHeadIndex(newWorm, 0);
    setMaxIndex(newWorm, WORM_MAX_LENGTH);
    setWormpos(newWorm, startPos);
    setWormColor(newWorm, color);

    // place Worm on Board
    placeItem(theBoard, startPos, SYMBOL_WORM_HEAD_ELEMENT, BC_USED_BY_WORM, color);

    // return pointer
    return newWorm;
}

worm_t* initializeUserWorm(board_t* theBoard)
{
    // set default Values for userworm
    pos_t startPos;

    // set startpos to bottom left
    startPos.x = 0;
    startPos.y = BOARD_MIN_HEIGHT - 2;

    return initializeWorm(theBoard, startPos, WORM_RIGHT, COLP_WORM_USER);
}

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

void setWormHeading(worm_t* theWorm, wormheading_t dir)
{
    pos_t nextStep;

    switch(dir){
        case WORM_UP:
            // user wants to move up
            nextStep.x = 0;
            nextStep.y = -1;
            break;
        case WORM_DOWN:
            // user wants to move down
            nextStep.x = 0;
            nextStep.y = 1;
            break;
        case WORM_LEFT:
            // user wants to move left
            nextStep.x = -1;
            nextStep.y = 0;
            break;
        case WORM_RIGHT:
            // user wants to move right
            nextStep.x = 1;
            nextStep.y = 0;
            break;
    }

    setNextStep(theWorm, nextStep);
}


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
