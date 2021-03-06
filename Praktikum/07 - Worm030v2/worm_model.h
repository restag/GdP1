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

#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// framework header
#include <stdbool.h>

// custom header
#include "gameops.h"            // for ResCodes
#include "prep.h"               // for ColorPairs


//*********************************************************
//* type definitions
//*********************************************************
// Directions for the worm
typedef enum WormHeading {
	WORM_UP,
	WORM_DOWN,
	WORM_LEFT,
	WORM_RIGHT,
} wormheading_t;


//*********************************************************
//* defines
//*********************************************************
// worm elements
#define SYMBOL_FREE_CELL ' '
#define SYMBOL_WORM_INNER_ELEMENT '0'
// worm settings
#define WORM_LENGTH 20          // Maximal length of the worm


//*********************************************************
//* function prototypes
//*********************************************************
// Functions concerning the management of the worm data
rescodes_t initializeWorm(int len_max, int headpos_y, int headpos_x, wormheading_t dir, colorpairs_t color);

// show & delete worm elements
void showWorm();
void cleanWormTail();

// worm movement
void moveWorm(gamestates_t* agame_state);

// collision detection
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x);

// Setters
extern void setWormHeading(wormheading_t dir);

#endif  // #define _WORM_MODEL_H
