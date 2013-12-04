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


#ifndef _PREP_H
#define _PREP_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here
#include <stdbool.h>

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// board dimensions
#define MIN_NUMBER_OF_ROWS 26    // The guaranteed number of rows available for the board
#define MIN_NUMBER_OF_COLS 70   // The guaranteed number of columns available for the board
#define ROWS_RESERVED 4         // rows reserved for messagebox

// Codes for the array of positions
#define UNUSED_POS_ELEM -1      // Unused element in the worm arrays of positions


//*********************************************************
//* structs
//*********************************************************
// put structs below here


//*********************************************************
//* type definitions
//*********************************************************
// Numbers for color pairs used by curses macro COLOR_PAIR
typedef enum ColorPairs{
    COLP_FREE_CELL,
    COLP_USER_WORM = 1,
    COLP_FOOD_1,
    COLP_FOOD_2,
    COLP_FOOD_3,
    COLP_BARRIER,
} colorpairs_t;


//*********************************************************
//* function prototypes
//*********************************************************
// Standard curses initialization and cleanup
void initializeCursesApplication(void); 
void cleanupCursesApp(void);

// pregame checks
bool windowHasMinSize(void);

// pregame setup
void initializeColors(void);

#endif  // #define _PREP_H
