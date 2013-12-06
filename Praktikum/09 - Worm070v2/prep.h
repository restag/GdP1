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
 * The "prep" files are used to check the window for the game requirements
 * and setup the window for modification by the gameboard
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
#include "messagearea_model.h"


//*********************************************************
//* defines
//*********************************************************
// board dimensions
#define MIN_NUMBER_OF_ROWS 26    // The guaranteed number of rows available for the board
#define MIN_NUMBER_OF_COLS 70   // The guaranteed number of columns available for the board


//*********************************************************
//* enums
//*********************************************************
// put enums below here


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here

//*********************************************************
//* structs
//*********************************************************
// put structs below here


//*********************************************************
//* struct type definitions
//*********************************************************
// put typedefs for structs here

//*********************************************************
//* function prototypes
//*********************************************************
// Standard curses initialization and cleanup
void initializeCursesApp(void); 
void cleanupCursesApp(void);

// pregame checks
bool windowHasMinSize(void);

#endif  // #define _PREP_H
