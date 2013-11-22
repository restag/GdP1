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

#ifndef _GAMEOPS_H
#define _GAMEOPS_H
//*********************************************************
//* header includes 
//*********************************************************
//none


//*********************************************************
//* type definitions
//*********************************************************
// Result codes of functions
typedef enum ResCodes {
	RES_OK,
	RES_FAILED,
} rescodes_t;


//*********************************************************
//* defines
//*********************************************************
// game setting
#define NAP_TIME 100            // Time in milliseconds to sleep between updates of display


//*********************************************************
//* function prototypes
//*********************************************************
void initializeColors();
void readUserInput(gamestates_t* agame_state );
rescodes_t doLevel();


#endif  // #define _GAMEOPS_H
