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
                placeItem(newBoard, curPos, SYMBOL_BOARD_BARRIER, BC_BARRIER, COLP_BOARD_BARRIER);
            } else {
                // place free cell
                placeItem(newBoard, curPos, SYMBOL_FREE_CELL, BC_FREE_CELL,COLP_FREE_CELL);
            }
        }
    }

    // setNumber of Food items
    setNumberOfFoodItems(newBoard, GAME_INITIAL_FOOD_ITEMS);
    
    // return pointer to board
    return newBoard;
}

void initializeBarriers(board_t* theBoard)
{
    int i;
    pos_t curPos;

    // set position to left third of the board
    curPos.x = BOARD_MIN_WIDTH / 3;
    for (i = 0; i < 12; i++){
        curPos.y = BOARD_MIN_HEIGHT / 3 + i;
        placeItem(theBoard, curPos, SYMBOL_BOARD_BARRIER, BC_BARRIER, COLP_BOARD_BARRIER);
    }

    // set porition the right third of the board
    curPos.x *= 2;
    for (i = 0; i < 12; i++){
        curPos.y = BOARD_MIN_HEIGHT / 4 + i;
        placeItem(theBoard, curPos, SYMBOL_BOARD_BARRIER, BC_BARRIER, COLP_BOARD_BARRIER);
    }
}

void initializeFoodItems(board_t* theBoard)
{
    pos_t curPos[GAME_INITIAL_FOOD_ITEMS];
    
    // set food positions
    curPos[0].x = 11;
    curPos[0].y = 4;
    curPos[1].x = 14;
    curPos[1].y = 14;
    curPos[2].x = 19;
    curPos[2].y = 17;
    curPos[3].x = 5;
    curPos[3].y = 5;
    curPos[4].x = 60;
    curPos[4].y = 10;
    curPos[5].x = 55;
    curPos[5].y = 15;
    curPos[6].x = 48;
    curPos[6].y = 19;
    curPos[7].x = 22;
    curPos[7].y = 22;
    curPos[8].x = 52;
    curPos[8].y = 22;
    curPos[9].x = 38;
    curPos[9].y = 20;

    int i;
    
    // food type 1
    for (i = 0; i < GAME_FOOD_ITEMS_1; i++){
        placeItem(theBoard, curPos[i], SYMBOL_FOOD_1, BC_FOOD_1, COLP_FOOD_1);
    }

    // food type 1
    for (; i < (GAME_FOOD_ITEMS_1 + GAME_FOOD_ITEMS_2); i++){
        placeItem(theBoard, curPos[i], SYMBOL_FOOD_2, BC_FOOD_2, COLP_FOOD_2);
    }

    // food type 3
    for (;i < GAME_INITIAL_FOOD_ITEMS;i++){
        placeItem(theBoard, curPos[i], SYMBOL_FOOD_3, BC_FOOD_3, COLP_FOOD_3);
    }
}


//*********************************************************
//* free module


//*********************************************************
//* module management


//*********************************************************
//* module content management
void placeItem(board_t* theBoard, pos_t position, char symbol, boardcodes_t boardcode, colorpairs_t color)
{
    // set cell content
    setCellContent(theBoard, position, boardcode);

    // print to display
    printItem(position, symbol, color);
}

gamestates_t decrementNumberOfFoodItems(board_t* theBoard, gamestates_t* theGamestate)
{
    theBoard -> food_items--;

    if (theBoard -> food_items == 0){
        return BOARD_NO_FOOD_LEFT;
    }

    return WORM_GAME_ONGOING;
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
