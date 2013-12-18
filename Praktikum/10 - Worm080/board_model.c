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
pos_t makePos(int x, int y)
{
    pos_t newPos;

    newPos.x = x;
    newPos.y = y;

    return newPos;
}

board_t* allocBoard(void)
{
    board_t* newBoard = malloc(sizeof(board_t));

    return newBoard;
}

boardcodes_t* allocCells(theBoard)
{
    // alloc board rows
    setCellContentarray(theBoard, malloc((getLastRowOnBoard(aboard) + 1) * sizeof(struct pos*)));

    // set rows of 2 dim array
    if (getBoardCellarray(theBoard) == NULL){
        //print error
    }

    int i;
    for (i = 0; i < getLastColOnBoard; i++){
        setPosarrayAtRow(malloc((getLastColOnBoard(aboard) + 1) * sizeof(struct pos)) , i);
        if (getPosarrayAtIndex(getBoardCellarray(theBoard), i) == NULL){
            // print error
        }
    }

    return getBoardCellarray(theBoard);
}

//*********************************************************
//* free model
void freeBoard(board_t* theBoard)
{
    free(theBoard);
}

void freeCells(board_t* theBoard)
{
    // free child arrays
    int i;
    for (i = 0; i <= getLastRowOnBoard) {
        free(getPosarrayAtIndex(getBoardCellarray(theBoard)), i);
    }

    //free parent array
    free(getBoardCellarray(theBoard));
}

//*********************************************************
//* setters
void setXPos(pos_t* thePos, int n)
{
    thePos -> x = n;
}

void setYPos(pos_t* thePos, int n)
{
    thePos -> y = n;
}

void setLastRowOnBoard(board_t* theBoard, int lastRow)
{
    theBoard -> last_row = lastRow;
}

void setLastColOnBoard(board_t* theBoard, int lastCol)
{
    theBoard -> last_col = lastCol;
}

void setCellContentAtPos(board_t* theBoard, pos_t* cellPos, boardcodes_t cellContent)
{
    theBoard -> cells[getYPos(cellPos)][getXPos(cellPos)] = cellContent;
}

void setNumberOfFoodItems(board_t* theBoard, int n)
{
    theBoard -> food_items = n;
}

//*********************************************************
//* getters
int getXPos(pos_t* thePos)
{
    return thePos -> x;
}

int getYPos(pos_t* thePos)
{
    return thePos -> y;
}

int getLastRowOnBoard(board_t* theBoard)
{
    return theBoard -> last_row;
}

int getLastColOnBoard(board_t* theBoard)
{
    return theBoard -> last_col;
}

boardcodes_t getCellContentAtPos(board_t* theBoard, pos_t* thePos)
{
    return theBoard -> cells[getYPos(thePos)][getXPos(thePos)];
}

int getNumberOfFoodItems(board_t* theBoard)
{
    return theBoard -> food_items;
}
