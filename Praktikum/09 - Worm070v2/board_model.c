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
#include <stdlib.h>

// put custom header includes below here
#include "board_model.h"


//*********************************************************
//* fuctions
//*********************************************************

board_t* allocBlankBoard()
{
    board_t* theBoard= malloc(sizeof(board_t));

    return theBoard;
}

void freeBoard(board_t* aBoard)
{
    free(aBoard);
}

//* setters
extern void setNumberOfFoodItems(board_t* aboard, int n)
{
    aboard -> food_items = n;
}

//* Getters
// Get the last usable row and col
int getLastRowOnBoard(board_t* aboard)
{
    return aboard -> last_row;
}

int getLastColOnBoard(board_t* aboard)
{
    return aboard -> last_col;
}

// count remaining food items
int getNumberOfFoodItems(board_t* aboard)
{
    return aboard -> food_items;
}
