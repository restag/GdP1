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
 * The userinteractioncontroller is used for user interaction
 *
 * Tasks:
 *      * reading the keyboard input
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>

// put custom header includes below here
#include "userinteraction_controller.h"
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


//*********************************************************
//* input management
void readUserInput(worm_t* theWorm, gamestates_t* theGamestate)
{
    int ch;     // For storing the key codes

    if ((ch = getch()) > 0) {
        // is there some user input?
        // blocking or non-blocking depends on config of getch

        switch(ch) {
            case 'q':
                // user wants to quit
                *theGamestate = WORM_GAME_QUIT;
                break;
            case 's':
                // user wants to enter single step mode
                nodelay(stdscr, FALSE); // make getch blocking
                break;
            case ' ':
                // user wants to enter automatic mode
                nodelay(stdscr, TRUE);  // make getch non-blocking
                break;
            case KEY_UP:
                // user wants to move up
                setWormHeading(theWorm, WORM_UP);
                break;
            case KEY_DOWN:
                // user wants to move down
                setWormHeading(theWorm, WORM_DOWN);
                break;
            case KEY_LEFT:
                // user wants to move left
                setWormHeading(theWorm, WORM_LEFT);
                break;
            case KEY_RIGHT:
                // user wants to move right
                setWormHeading(theWorm, WORM_RIGHT);
                break;
        }
    }
    return;
}

//*********************************************************
//* display management


//*********************************************************
//* display interaction
