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
 * The displaycontroller is used to handle the display interaction for the app.
 * 
 * Tasks:
 *      * display intitialization & cleanup
 *      * colormanagement
 *      * writing to display
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>
#include <stdio.h>

// put custom header includes below here
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
void initializeColors(void)
{
    // define colors for the game
    start_color();
    init_pair(COLP_BARRIER, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLP_BOARD_BARRIER, COLOR_RED, COLOR_BLACK);
    init_pair(COLP_MESSAGEAREA_BORDER, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLP_FOOD_1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLP_FOOD_2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLP_FOOD_3, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLP_FREE_CELL, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLP_WORM_USER, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLP_DEFAULT, COLOR_WHITE, COLOR_BLACK);
}

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


//*********************************************************
//* free module
void cleanupCursesApp(void)
{
    standend();             // turn off all attibutes
    refresh();              // write changes to terminal
    curs_set(1);            // make cursor visible
    endwin();               // terminate curses application
}


//*********************************************************
//* module management


//*********************************************************
//* module content management


//*********************************************************
//* output management
colorpairs_t detectColor(char symbol)
{
    colorpairs_t color_pair;
    
    // define the output color
    switch (symbol){
        case SYMBOL_BOARD_BARRIER:
            color_pair = COLP_BOARD_BARRIER;
            break;
        case SYMBOL_MESSAGEAREA_BORDER:
            color_pair = COLP_MESSAGEAREA_BORDER;
            break;
        case SYMBOL_FOOD_1:
            color_pair = COLP_FOOD_1;
            break;
        case SYMBOL_FOOD_2:
            color_pair = COLP_FOOD_2;
            break;
        case SYMBOL_FOOD_3:
            color_pair = COLP_FOOD_3;
            break;
        case SYMBOL_FREE_CELL:
            color_pair = COLP_FREE_CELL;
            break;
        default:
            color_pair = COLP_DEFAULT;
    }

    // return detected color
    return color_pair;
}

void fillDisplaylineWithSymbol(int lineIndex, char symbol)
{
    fillPartialDisplaylineWithSymbol(lineIndex, symbol, 0, BOARD_MIN_WIDTH - 1);
}

void fillPartialDisplaylineWithSymbol(int lineIndex, char symbol, int startIndex, int endIndex){
    // detect the color to use
    colorpairs_t color = detectColor(symbol);

    // fill line with symbol
    int i;
    for (i = startIndex; i <= endIndex; i++) {
        // place symbol
        placeItemInDisplay(i, lineIndex, symbol, color);
    }
}


//*********************************************************
//* display management


//*********************************************************
//* display interaction
void placeItemInDisplay(int xindex, int yindex, char symbol, colorpairs_t color)
{
    // move to position
    move(yindex, xindex);
   
    // activate the color
    attron(COLOR_PAIR(color));

    // print symbol
    addch(symbol);

    // deactivate color
    attroff(COLOR_PAIR(color));
}

void refreshDisplay(void)
{
    refresh();
}
