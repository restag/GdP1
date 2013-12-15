 /* This version is an alternativ version of the given code,
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
 * The pregamecontroller is used to do pregame checks.
 *
 * Tasks:
 *      * size of the terminal window
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>

// put custom header includes below here
#include "pregame_controller.h"
#include "board_model.h"
#include "messagearea_model.h"

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
bool windowCanContainMessagearea(void)
{
    if (LINES < MESSAGEAREA_MIN_HEIGHT || COLS < BOARD_MIN_WIDTH){
        // window is too small for messagearea
        return false;
    }

    // window is big enough to fit the messagearea
    return true;
}

bool windowCanContainMessageareaAndBoard(void)
{
    if (LINES < WINDOW_MIN_HEIGHT || COLS < BOARD_MIN_WIDTH){
        // window is too small to fit the messagearea and the gameboard
        return false;
    }

    // window is big enough to fit the messagearea and the gameboard
    return true;
}

//*********************************************************
//* module content management


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
