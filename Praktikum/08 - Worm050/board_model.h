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

#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
#include <curses.h>             // for chtype

// include custom headers here
#include "prep.h"               // for ColorPairs


//*********************************************************
//* type definitions & structs
//*********************************************************
// position on the board
struct pos {
    int y;  // y-coordinate (row)
    int x;  // x-coordinate (col)
};

typedef struct pos pos_t;
//*********************************************************
//* defines
//*********************************************************
// board
#define SYMBOL_BARRIER '#'


//*********************************************************
//* function prototypes
//*********************************************************
//placing & removing items from the board
void placeItem(pos_t posi, chtype symbol, colorpairs_t color_pair);

// Getters
extern int getLastRow();
extern int getLastCol();

#endif  // #define _BOARD_MODEL_H
