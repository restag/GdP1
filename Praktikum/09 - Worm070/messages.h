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

#ifndef _MESSAGES_H
#define _MESSAGES_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_model.h"
#include "board_model.h"


//*********************************************************
//* defines
//*********************************************************
// put defines below here


//*********************************************************
//* structs
//*********************************************************
// put structs below here


//*********************************************************
//* type definitions
//*********************************************************
// put typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// messagebox
extern void clearLineInMessageArea(int row);
extern void showStatus(worm_t* aworm);
extern int showDialog(char* prompt1, char* prompt2);

#endif  // #define _MESSAGES_H
