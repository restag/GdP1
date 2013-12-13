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
#include <curses.h>

// put custom header includes below here
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
//* color detection
colorpairs_t detectColor(char symbol)
{
    colorpairs_t color_pair;
    
    // define the output color
    switch (symbol){
        case SYMBOL_BORDER_BOARD:
            color_pair = COLP_BORDER_BOARD;
            break;
        case SYMBOL_BORDER_MESSAGEAREA:
            color_pair = COLP_BORDER_MESSAGEAREA;
            break;


    }

    // return detected color
    return color_pair;
}


//* single item placement
void placeItemInDisplay(pos_t index, char symbol)
{
    // detect the color to use
    colorpairs_t color = detectColor(symbol);

    // move to position
    move(index.y, index.x);
   
    // activate the color
    attron(COLOR_PAIR(color));

    // print symbol
    addch(symbol);

    attroff(COLOR_PAIR(color));
}

//*********************************************************
//* line placement
void fillDisplaylineWithSymbol(int lineIndex, char symbol)
{
    int i;

    // detect the color to use
    colorpairs_t color = detectColor(symbol);

   
    // fill line with symbol
    for (i = 1; i < BOARD_MIN_WIDTH && i < COLS; i++) {
        
        move(lineIndex, i);
        // activate the color
        attron(COLOR_PAIR(color));
        
        // place symbol
        addch(symbol);
        
        //deactivate the color
        attroff(COLOR_PAIR(color));
    }
}
