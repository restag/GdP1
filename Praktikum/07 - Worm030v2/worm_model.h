// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The worm model

#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H

#include "worm.h"

// Directions for the worm
typedef enum WormHeading {
	WORM_UP,
	WORM_DOWN,
	WORM_LEFT,
	WORM_RIGHT,
} wormheading_t;

// Functions concerning the management of the worm data
extern rescodes_t initializeWorm(int len_max, int headpos_y, int headpos_x, wormheading_t dir, colorpairs_t color);
extern void showWorm();
extern void cleanWormTail();
extern void moveWorm(gamestates_t* agame_state);
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x);

// Setters
extern void setWormHeading(wormheading_t dir);

#endif  // #define _WORM_MODEL_H
