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

#include <stdbool.h>
#include "worm.h"

// Directions for the worm
typedef enum WormHeading {
	WORM_UP,
	WORM_DOWN,
	WORM_LEFT,
	WORM_RIGHT,
} worm_heading_t;

// Functions concerning the management of the worm data
extern res_codes_t initializeWorm(int len_max, int headpos_y, int headpos_x, worm_heading_t dir, color_pairs_t color);
extern void showWorm();
extern void cleanWormTail();
extern void moveWorm(game_states_t* agame_state);
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x);

// Setters
extern void setWormHeading(worm_heading_t dir);

#endif  // #define _WORM_MODEL_H
