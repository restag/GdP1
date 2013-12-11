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

#ifndef _MESSAGEAREA_MODEL_H
#define _MESSAGEAREA_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "message_model.h"

//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define MESSAGEAREA_MIN_HEIGHT 4
#define MESSAGEAREA_BLANKS_RESERVED_LEFT 1
#define MESSAGEAREA_BLANKS_RESERVED_RIGHT 1


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
struct MessageArea {
    int baseIndex;
    message_t* messageLine[MESSAGEAREA_MIN_HEIGHT - 1];
};


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct MessageArea messagearea_t;


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

// setters

// getters

#endif  // #define _MESSAGEAREA_MODEL_H
