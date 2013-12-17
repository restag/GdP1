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
 * The displaymodel contains the data needed for display interaction.
 * 
 * Tasks:
 *      * colormanagement
 *
 */

#ifndef _DISPLAY_MODEL_H
#define _DISPLAY_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// put defines below here


//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum ColorPairs {
    COLP_BARRIER,
    COLP_BOARD_BARRIER,
    COLP_MESSAGEAREA_BORDER,
    COLP_FOOD_1,
    COLP_FOOD_2,
    COLP_FOOD_3,
    COLP_FREE_CELL,
    COLP_WORM_USER,
    COLP_DEFAULT,
};


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum ColorPairs colorpairs_t;

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

//* module content management

//* output management

//* display management

//* display interaction

#endif  // #define _DISPLAY_CONTROLLER_H
