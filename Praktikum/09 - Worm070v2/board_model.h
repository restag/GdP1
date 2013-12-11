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

//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define BOARD_MIN_HEIGHT 26
#define BOARD_MIN_WIDTH 70

//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum BoardCodes {
    BC_FREE_CELL,       // Cell is free
    BC_USED_BY_WORM,    // Cell is occupied by worm
    BC_FOOD_1,          // food type 1; if hit => bonus type 1
    BC_FOOD_2,          // food type 2; if hit => bonus type 2
    BC_FOOD_3,          // food type 3; if hit => bonus type 3
    BC_BARRIER,         // a barrier; if hit => game over
};

enum ColorPairs {
    COLP_FREE_CELL,
    COLP_USER_WORM,
    COLP_FOOD_1,
    COLP_FOOD_2,
    COLP_FOOD_3,
    COLP_BARRIER,
};

//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum BoardCodes boardcodes_t;
typedef enum ColorPairs colorpairs_t;

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

    boardcodes_t cells[BOARD_MIN_HEIGHT][BOARD_MIN_WIDTH];
    /**
     * a 2-dimensional array for storing the contents of the board.
     *
     * Since the worm is not permitted to cross over itself, nor
     * other elements (besides food) we do not need a reference counter for occupied cells.
     */

    int food_items; // number of food items left in the current level
};

//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct pos pos_t;
typedef struct board board_t;


//*********************************************************
//* function prototypes
//*********************************************************


// initializers

// setters
void setLastRow(board_t* aboard);
void setLastCol(board_t* aboard);
void setCellContent(board_t* aboard, pos_t cellPos, boardcodes_t cellContent); 
extern void setNumberOfFoodItems(board_t* aboard, int n);

// getters
int getLastRowOnBoard(board_t* aboard);
int getLastColOnBoard(board_t* aboard);
extern boardcodes_t getContentAt(board_t* aboard, pos_t pos);
int getNumberOfFoodItems(board_t* aboard);
boardcodes_t getContentAt(board_t* aboard, pos_t position);

#endif  // #define _BOARD_MODEL_H
