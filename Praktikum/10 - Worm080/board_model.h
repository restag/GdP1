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


#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// put defines below here
// board dimensions
#define BOARD_MIN_HEIGHT 26
#define BOARD_MIN_WIDTH 70

// symbols placed on gameboard
#define SYMBOL_FREE_CELL ' '
#define SYMBOL_BOARD_BARRIER '#'
#define SYMBOL_BOARD_BORDER '='
#define SYMBOL_FOOD_1 '2'
#define SYMBOL_FOOD_2 '4'
#define SYMBOL_FOOD_3 '6'
#define SYMBOL_WORM_HEAD_ELEMENT '0'
#define SYMBOL_WORM_INNER_ELEMENT 'o'
#define SYMBOL_WORM_TAIL_ELEMENT '`'

//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum BoardCodes {
    BC_BARRIER,             // a barrier; if hit => game over
    BC_FOOD_1,              // food type 1; if hit => bonus type 1
    BC_FOOD_2,              // food type 2; if hit => bonus type 2
    BC_FOOD_3,              // food type 3; if hit => bonus type 3
    BC_FREE_CELL,           // Cell is free
    BC_USED_BY_WORM,    // Cell is occupied by userworm    
};

enum Boni {
    BONUS_1 = 2,        // additional length for the worm when consuming
    BONUS_2 = 4,
    BONUS_3 = 6,
};


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum BoardCodes boardcodes_t;
typedef enum Boni bonus_t;

//*********************************************************
//* structs
//*********************************************************
// put structs below here
struct pos {
    int y;  // y-coordinate (row)
    int x;  // x-coordinate (col)
};

struct board {
    int last_row;   // last usable row on the board
    int last_col;   // last usable col on the board

    boardcodes_t** cells;
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
// put prototypes below here

//* model allocation
pos_t makePos(int x, int y);
board_t* allocBoard(void);

//* free model
void freeBoard(board_t* aBoard);

//* model setters
void setXPos(pos_t* aPos, int x);
void setYPos(pos_t* aPos, int y);
void setLastRowOnBoard(board_t* aBoard, int lastRow);
void setLastColOnBoard(board_t* aBoard, int lastCol);
void setBoardCellarray(aBoard, pos_t* anArray);
void setPosarrayAtRow(pos_t* aPosarray, int index);
void setCellContentAtPos(board_t* aBoard, pos_t* cellPos, boardcodes_t cellContent); 
void setNumberOfFoodItems(board_t* aBoard, int n);

//* model getters
int getXPos(pos_t* aPos);
int getYPos(pos_t* aPos);
int getLastRowOnBoard(board_t* aBoard);
int getLastColOnBoard(board_t* aBoard);
boardcodes_t* getBoardCellarray(board_t*);
boardcodes_t getCellContentAtPos(board_t* aBoard, pos_t* aPos);
int getNumberOfFoodItems(board_t* aBoard);

#endif  // #define _BOARD_MODEL_H
