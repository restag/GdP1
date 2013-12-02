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

#include "prep.h"               // for ColorPairs


//*********************************************************
//* type definitions
//*********************************************************
// none


//*********************************************************
//* defines
//*********************************************************
// none


//*********************************************************
//* function prototypes
//*********************************************************
//placing & removing items from the board
extern void placeItem(int y, int x, chtype symbol, colorpairs_t color_pair);

// Getters
extern int getLastRow();
extern int getLastCol();

#endif  // #define _BOARD_MODEL_H
