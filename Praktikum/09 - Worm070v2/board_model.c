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

//* initializers
void initializeDefaultBoard(board_t* theBoard)
{
    // board dimensions
    setLastRow(theBoard);
    setLastCol(theBoard);

    // Cell Content
    int rowIndex, colIndex;
    pos_t curCell;

    for (rowIndex = 0; rowIndex <= theBoard -> last_row; rowIndex++) {
        for(colIndex = 0; colIndex <= theBoard -> last_col; colIndex++) {
            curCell.x = colIndex;
            curCell.y = rowIndex;
            setCellContent(theBoard, curCell, BC_FREE_CELL);
        }
    }

    // food items
    setNumberOfFoodItems(theBoard, 0);
}

//* setters
void setLastRow(board_t* theBoard)
{
    theBoard -> last_row = MIN_NUMBER_OF_ROWS - MESSAGEAREA_MIN_HEIGHT;
}

void setLastCol(board_t* theBoard)
{
    theBoard -> last_col = MIN_NUMBER_OF_COLS;
}

void setCellContent(board_t* theBoard, pos_t cellPos, boardcodes_t cellContent)
{
    theBoard -> cells[cellPos.y][cellPos.x] = cellContent;
}

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
