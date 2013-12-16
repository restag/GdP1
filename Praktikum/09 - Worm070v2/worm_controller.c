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
#include <stdlib.h>

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

    // set wormposarray to unusedPos
    int i;
    pos_t unusedPos;
    unusedPos.x = -1;
    unusedPos.y = -1;
    for (i = 0; i < WORM_MAX_LENGTH; i++){
        newWorm -> wormpos[i] = unusedPos;
    }

    // set default values
    setWormInitialLength(newWorm);
    setHeadIndex(newWorm, 0);
    setMaxIndex(newWorm, WORM_MAX_LENGTH);
    setWormpos(newWorm, startPos);
    setWormColor(newWorm, color);
    setWormHeading(newWorm, dir);

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
void moveWorm(board_t* theBoard, worm_t* theWorm, gamestates_t* theGamestate)
{
    // get worm's headpos
    pos_t headpos = getWormHeadpos(theWorm);
    headpos.x += theWorm -> nextStep.x;
    headpos.y += theWorm -> nextStep.y;

    // check if we hit something
    if (headpos.x < 0) {
        *theGamestate = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastColOnBoard(theBoard)) {
        *theGamestate = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y < 0){
        *theGamestate = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y > getLastRowOnBoard(theBoard)) {
        *theGamestate = WORM_OUT_OF_BOUNDS;
    } else {
        // we stay on the board, so check for hitting something
        switch(getContentAt(theBoard, headpos)){
            case BC_FOOD_1:
                //grow worm
                growWorm(theWorm, BONUS_1);
                *theGamestate = decrementNumberOfFoodItems(theBoard, theGamestate);
                break;
            case BC_FOOD_2:
                growWorm(theWorm, BONUS_2);
                *theGamestate = decrementNumberOfFoodItems(theBoard, theGamestate);
                break;
            case BC_FOOD_3:
                growWorm(theWorm, BONUS_3);
                *theGamestate = decrementNumberOfFoodItems(theBoard, theGamestate);
                break;
            case BC_BARRIER:
                // thats bad, we crashed into the wall
                *theGamestate = WORM_CRASH;
                break;
            case BC_USED_BY_WORM:
                // bad, worm bit itself
                *theGamestate = WORM_CROSSING;
                break;
            default:
                // without default we get warning
                {;} // do nothing
        }
    }

    // check the gamestatus
    if (*theGamestate == WORM_GAME_ONGOING){
        // all is good
        // go round if end of worm is reached (ring buffer)
        theWorm->headindex++;
        if (theWorm->headindex > theWorm->cur_lastindex){
            theWorm->headindex = 0;
        }

        // store new coordinates
        setWormpos(theWorm, headpos);
    }
}

void growWorm(worm_t* theWorm, bonus_t growth)
{
    if (getWormLength(theWorm) + growth >= getMaxIndex(theWorm)){
        setCurLastindex(theWorm, getMaxIndex(theWorm));
    } else {
        theWorm -> cur_lastindex += growth;
    }
}


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

void cleanWormTail(board_t* theBoard, worm_t* theWorm)
{
    int tailindex;

    // compute tailindex
    tailindex = (getHeadindex(theWorm) + 1) % getWormLength(theWorm);

    pos_t tailpos = getWormposAtIndex(theWorm, tailindex);

    // check if the tail exists
    // is the wormpos @ tailindex already in use?
    if (tailpos.x != -1) {
        // remove tail from board
        placeItem(theBoard, tailpos, SYMBOL_FREE_CELL, BC_FREE_CELL, COLP_FREE_CELL);
    }
}


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
void showWorm(board_t* theBoard, worm_t* theWorm)
{
    pos_t curPos;
    int curIndex;
    int headindex = getHeadindex(theWorm);
    colorpairs_t color = getWormColor(theWorm);


    // place new Body element
    if (headindex == 0){
        curIndex = theWorm -> cur_lastindex;
    } else {
        curIndex = headindex -1;
    }

    curPos = getWormposAtIndex(theWorm, curIndex);
    placeItem(theBoard, curPos, SYMBOL_WORM_INNER_ELEMENT, BC_USED_BY_WORM, color);

    // place tail element
    if (headindex == theWorm -> cur_lastindex){
        curIndex = 0;
    } else {
        curIndex = headindex + 1;
    }

    curPos = getWormposAtIndex(theWorm, curIndex);
    if (curPos.x == -1 && curPos.y == -1){
        curPos = getWormposAtIndex(theWorm, 0);
    }

    placeItem(theBoard, curPos, SYMBOL_WORM_TAIL_ELEMENT, BC_USED_BY_WORM, color);

    // place the new head
    placeItem(theBoard, getWormHeadpos(theWorm), SYMBOL_WORM_HEAD_ELEMENT, BC_USED_BY_WORM, color);
}
