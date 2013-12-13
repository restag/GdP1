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
 * The "prep" files are used to check the window for the game requirements
 * and setup the window for modification by the gameboard
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>

// put custom header includes below here
#include "prep.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* Standard curses initialization and cleanup
void initializeCursesApp(void)
{
    initscr();  // initialize the curses screen
    // note:
    // initscr() defines various global vars of the curses framework.
    // stdscr, LINES, COLS, true, false


    noecho();               // Characters typed are not echoed
    cbreak();               // no buffering of stdin
    nonl();                 // do not translate "return key" on keyboard
    keypad(stdscr, TRUE);   // enable keypad
    curs_set(0);            // make cursor invisible


    // Begin in non-single-step mode (getch => non-blocking)
    nodelay(stdscr, TRUE);  // make getch non-blocking
}

void cleanupCursesApp(void)
{
    standend();             // turn off all attibutes
    refresh();              // write changes to terminal
    curs_set(1);            // make cursor visible
    endwin();               // terminate curses application
}

//*********************************************************
//* pregame checks

// Maximal LINES and COLS for the current window size are set by curses.
// note: we do not cope with resizing in this simple examples!

bool windowFitsMessagearea(void)
{
    if (LINES < MESSAGEAREA_MIN_HEIGHT || COLS < BOARD_MIN_WIDTH) {
        return false;
    }

    return true;
}

bool windowFitsMessageareaAndBoard(void)
{
    if (LINES < WINDOW_MIN_HEIGHT || COLS < BOARD_MIN_WIDTH) {
        return false;
    }

    return true;
}

//*********************************************************
//* pregame setup

void initializeColors(void)
{
    // define colors for the game
    start_color();
    init_pair(COLP_USER_WORM, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLP_FREE_CELL, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLP_BORDER_BOARD, COLOR_RED, COLOR_BLACK);
    init_pair(COLP_BORDER_MESSAGEAREA, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLP_FOOD_1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLP_FOOD_2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLP_FOOD_3, COLOR_CYAN, COLOR_BLACK);
}
