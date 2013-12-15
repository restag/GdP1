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
 * The boardcontroller is used for boar interaction
 *
 * Tasks:
 *      * initialization
 *      * handling
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include "stdlib.h"

// put custom header includes below here
#include "board_controller.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initialize module
board_t* initializeBoard(void)
{
    // reserve memory
    board_t* newBoard = allocBoard();

    // initialize fixed default values
    setLastRow(newBoard);
    setLastCol(newBoard);

    // initialize cell default contents
    pos_t curPos;
    int colIndex;
    int lineIndex;
    int lastRow = getLastRowOnBoard(newBoard);
    int lastCol = getLastColOnBoard(newBoard);

    for (lineIndex = 0; lineIndex <= lastRow; lineIndex++){
        // set current line to position helper
        curPos.y = lineIndex;

        for (colIndex = 0; colIndex <= lastCol; colIndex++){
            // set current col to position helper
            curPos.x = colIndex;

            // check for board border
            if (colIndex == lastCol || lineIndex == lastRow){
                // place barrier
                placeBarrier(newBoard, curPos);
            } else {
                // place free cell
                placeFreeCell(newBoard, curPos);
            }
        }
    }

    // setNumber of Food items
    setNumberOfFoodItems(newBoard, 10);
    
    // return pointer to board
    return newBoard;
}

void initializeLevel(board_t* theBoard)
{
    // initialize barriers
    int i;
    pos_t curPos;

    // set position to left third of the board
    curPos.x = BOARD_MIN_WIDTH / 3;
    for (i = 0; i < 12; i++){
        curPos.y = BOARD_MIN_HEIGHT / 3 + i;
        placeBarrier(theBoard, curPos);
    }

    // set porition the right third of the board
    curPos.x *= 2;
    for (i = 0; i < 12; i++){
        curPos.y = BOARD_MIN_HEIGHT / 4 + i;
        placeBarrier(theBoard, curPos);
    }
}


//*********************************************************
//* free module


//*********************************************************
//* module management


//*********************************************************
//* module content management
void placeBarrier(board_t* theBoard, pos_t position)
{
    // set cell content
    setCellContent(theBoard, position, BC_BARRIER);

    // print to display
    printItem(position, SYMBOL_BOARD_BARRIER, COLP_BOARD_BARRIER);
}

void placeFreeCell(board_t* theBoard, pos_t position)
{
    // set cell content
    setCellContent(theBoard, position, BC_FREE_CELL);

    // print to display
    printItem(position, SYMBOL_FREE_CELL, COLP_FREE_CELL);
}


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
void printItem(pos_t position, char symbol, colorpairs_t color)
{
    placeItemInDisplay(position.x, position.y, symbol, color);
}
