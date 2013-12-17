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
#include <stdlib.h>
#include <unistd.h>

// put custom header includes below here
#include "pregame_controller.h"
#include "display_controller.h"

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

void usage(void)
{
    //printStringToTerminal("Aufruf: worm [-h] [-n ms] [-s]");
}

// read the commandline options
rescodes_t readCommandLineOptions(settings_t* settingsset, int argc, char* argv[])
{
    char c;

    while((c = getopt(argc, argv, "n:s")) != -1)
        switch(c) {
            case('h'):
                usage();
                return RES_WRONG_OPTION;
            case('n'):
                setNaptime(settingsset, atoi(optarg));
                continue;
            case('s'):
                setStartInSingleStepFlag(settingsset, true);
                continue;
            default:
                usage();
                return RES_WRONG_OPTION;
        }

    // skip all options processed
    argc -= optind;
    argv += optind;

    // Are there any non-option arguments left?
    // In our case no further arguments are allowed
    if (argc > 0 ) {
        usage();
        return RES_WRONG_OPTION;
    }

    return RES_OK;
}

//*********************************************************
//* module content management


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
