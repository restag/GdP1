// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The board model

#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H

#include "prep.h"

// Placing and removing items from the game board
// Check boundaries of game board
extern void placeItem(int y, int x, chtype symbol, colorpairs_t color_pair);

// Getters
extern int getLastRow();
extern int getLastCol();

#endif  // #define _BOARD_MODEL_H
