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

// include headers below here
#include "board_model.h"
#include "prep.h"


//*********************************************************
//* fuctions
//*********************************************************
//* Place an item onto the curses display.
void placeItem(int y, int x, chtype symbol, colorpairs_t color_pair) {

    //  Store item on the display (symbol code)
    move(y, x);                         // Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));     // Start writing in selected color
    addch(symbol); 		 	// Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));    // Stop writing in selected color
}

//* Getters
// Get the last usable row on the display
int getLastRow() {
    return (LINES-1);
}

// Get the last usable column on the display
int getLastCol() {
    return (COLS-1);
}
