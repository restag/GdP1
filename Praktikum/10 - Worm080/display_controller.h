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
 * The displaycontroller is used to handle the display interaction for the app.
 * 
 * Tasks:
 *      * display intitialization & cleanup
 *      * colormanagement
 *      * writing to display
 *
 */

#ifndef _DISPLAY_CONTROLLER_H
#define _DISPLAY_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "display_model.h"
#include "board_model.h"
#include "messagearea_model.h"

//*********************************************************
//* defines
//*********************************************************
// put defines below here


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
// put struct typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

//* initialize module
void initializeColors(void);
void initializeCursesApp(void);

//* free module
void cleanupCursesApp(void);

//* module management

//* module content management

//* output management
colorpairs_t detectColor(char symbol);
void fillDisplaylineWithSymbol(int lineIndex, char symbol);
void fillPartialDisplaylineWithSymbol(int lineIndex, char symbol, int startIndex, int endIndex);

//* display management

//* display interaction
void placeItemInDisplay(int xindex, int yindex, char symbol, colorpairs_t color);
void refreshDisplay(void);

#endif  // #define _DISPLAY_CONTROLLER_H
