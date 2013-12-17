 /* This version is an alternativ version of the given code,
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
 * The pregamecontroller is used to do pregame checks.
 *
 * Tasks:
 *      * size of the terminal window
 */

#ifndef _PREGAME_CONTROLLER_H
#define _PREGAME_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here
#include <stdbool.h>

// put custom header includes below here
#include "board_model.h"
#include "game_model.h"
#include "messagearea_model.h"
#include "settings_model.h"

//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define WINDOW_MIN_HEIGHT (MESSAGEAREA_MIN_HEIGHT + BOARD_MIN_HEIGHT)

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

//* free module

//* module management
bool windowCanContainMessagearea(void);
bool windowCanContainMessageareaAndBoard(void);
void usage(void);
rescodes_t readCommandLineOptions(settings_t* settingsset, int argc, char* argv[]);

//* module content management

//* output management

//* display management

//* display interaction

#endif  // #define _PREGAME_CONTROLLER_H
