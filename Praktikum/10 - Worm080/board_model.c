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
 * The boardmodel contains the data needed for board creation and handling
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
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
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* model allocation
board_t* allocBoard(void)
{
    board_t* newBoard = malloc(sizeof(board_t));

    return newBoard;
}

//*********************************************************
//* free model
void freeBoard(board_t* theBoard)
{
    free(theBoard);
}

//*********************************************************
//* setters
void setCellContentAtPos(board_t* theBoard, pos_t cellPos, boardcodes_t cellContent)
{
    theBoard -> cells[cellPos.y][cellPos.x] = cellContent;
}

void setNumberOfFoodItems(board_t* theBoard, int n)
{
    theBoard -> food_items = n;
}

//*********************************************************
//* getters
int getLastRowOnBoard(board_t* theBoard)
{
    return theBoard -> last_row;
}

int getLastColOnBoard(board_t* theBoard)
{
    return theBoard -> last_col;
}

boardcodes_t getContentAt(board_t* theBoard, pos_t pos)
{
    return theBoard -> cells[pos.y][pos.x];
}

int getNumberOfFoodItems(board_t* theBoard)
{
    return theBoard -> food_items;
}
