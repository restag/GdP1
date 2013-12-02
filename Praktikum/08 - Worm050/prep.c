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
// include framework headers below here
#include <curses.h>
#include <stdbool.h>

// include headers below here
#include "prep.h"

//*********************************************************
//* fuctions
//*********************************************************
//* Standard curses initialization & cleanup
// Initialize application with respect to curses settings
void initializeCursesApplication(void)
{
    initscr(); // Initialize the curses screen

    // Note:
    // The call to initscr() defines various global variables of the curses framework.
    // stdscr, LINES, COLS, true, false

    noecho();  // Characters typed ar not echoed
    cbreak();  // No buffering of stdin
    nonl();    // Do not translate 'return key' on keyboard to newline character
    keypad(stdscr, TRUE); // Enable the keypad
    curs_set(0);          // Make cursor invisible
    // Begin in non-single-step mode (getch will not block)
    nodelay(stdscr, TRUE);  // make getch to be a non-blocking call
}

// Reset display to normale state and terminate curses application
void cleanupCursesApp(void)
{
    standend();   // Turn off all attributes
    refresh();    // Write changes to terminal
    curs_set(1);  // Set cursor state to normal visibility
    endwin();     // Terminate curses application
}


//*********************************************************
//* pregame Checks

// Check the minimum size of the terminal window
bool windowHasMinSize(void)
{
    // Maximal LINES and COLS are set by curses for the current window size.
    // Note: we do not cope with resizing in this simple examples!
    if (LINES < MIN_NUMBER_OF_ROWS || COLS < MIN_NUMBER_OF_COLS) {
        return false;
    }

    return true;
}

//*********************************************************
//* pregame setup
void initializeColors(void)
{
    // Define colors of the game
    start_color();
    init_pair(COLP_USER_WORM, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLP_FREE_CELL, COLOR_BLACK, COLOR_BLACK);
}
