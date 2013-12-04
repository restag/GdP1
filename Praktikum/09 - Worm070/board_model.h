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
// put framework header includes below here
#include <curses.h>             // for chtype

// put custom header includes below here
#include "prep.h"               // for ColorPairs
#include "gameops.h"


//*********************************************************
//* defines
//*********************************************************
// board
#define SYMBOL_BARRIER '#'
#define SYMBOL_FOOD_1 '2'
#define SYMBOL_FOOD_2 '4'
#define SYMBOL_FOOD_3 '6'

//*********************************************************
//* enums
//*********************************************************
// put enums below here
typedef enum BoardCodes {
    BC_FREE_CELL,       // cell is free
    BC_USED_BY_WORM,    // cell occupied by worm
    BC_FOOD_1,          // Food type 1, if hit by worm -> bonus of type 1
    BC_FOOD_2,          // Food type 2, if hit by worm -> bonus of type 2
    BC_FFOD_3,          // Food type 3, if hit by worm -> bonus of type 3
    BC_BARRIER          // a barrier, if hit by worm -> game over
} boardcodes_t;


//*********************************************************
//* structs
//*********************************************************
// put structs below here
// position on the board
struct pos {
    int y;  // y-coordinate (row)
    int x;  // x-coordinate (col)
};

struct board {
    int last_row;   // last usable row on the board
    int last_col;   // last usable col on the board

    boardcodes_t cells[MIN_NUMBER_OF_ROWS][MIN_NUMBER_OF_COLS];
    /**
     * a 2-dimensional array for storing the contents of the board.
     *
     * Since the worm is not permitted to cross over itself, nor
     * other elements (besides food) we do not need a reference counter for occupied cells.
     */

    int food_items; // number of food items left in the current level
};

//*********************************************************
//* type definitions
//*********************************************************
// put typedefs below here
//* structs
typedef struct pos pos_t;
typedef struct board board_t;


//*********************************************************
//* function prototypes
//*********************************************************
// board setup
extern rescodes_t initializeBoard(board_t* aboard);
extern rescodes_t initializeLevel(board_t* aboard);

// placing & removing items from the board
extern void placeItem(board_t* aboard, pos_t pos, boardcodes_t board_code, chtype symbol, colorpairs_t color_pair);

// setters
extern void decrementNumberOfFoodItems(board_t* aboard);
extern void setNumberOfFoodItems(board_t* aboard, int n);

// getters
extern int getNumberOfFoodItems(board_t* aboard);
extern boardcodes_t getContentAt(board_t* aboard, pos_t pos);
extern int getLastRowOnBoard(board_t* aboard);
extern int getLastColOnBoard(board_t* aboard);

#endif  // #define _BOARD_MODEL_H
