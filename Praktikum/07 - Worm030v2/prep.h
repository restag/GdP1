// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// Basic functions for initialization and cleanup of curses applications

#ifndef _PREP_H
#define _PREP_H
// board dimensions
#define MIN_NUMBER_OF_ROWS 5    // The guaranteed number of rows available for the board
#define MIN_NUMBER_OF_COLS 10   // The guaranteed number of columns available for the board


// Standard curses initialization and cleanup
void initializeCursesApplication(void); 
void cleanupCursesApp(void);

// pregame checks
bool windowHasMinSize(void);


// Numbers for color pairs used by curses macro COLOR_PAIR
typedef enum ColorPairs{
    COLP_FREE_CELL = 0,
    COLP_USER_WORM = 1,
} colorpairs_t;
#endif  // #define _PREP_H
