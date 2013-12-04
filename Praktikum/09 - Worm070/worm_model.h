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
// put framework header includes below here
#include <stdbool.h>

// put custom header includes below here
#include "prep.h"
#include "gameops.h"
#include "board_model.h"

//*********************************************************
//* defines
//*********************************************************
// worm elements
#define SYMBOL_FREE_CELL ' '
#define SYMBOL_WORM_HEAD_ELEMENT 'O'
#define SYMBOL_WORM_INNER_ELEMENT 'o'
#define SYMBOL_WORM_TAIL_ELEMENT '`'
// worm settings
#define WORM_LENGTH (MIN_NUMBER_OF_ROWS * MIN_NUMBER_OF_COLS)          // Maximal length of the worm
#define WORM_INITIAL_LENGTH 4   // initial length of the userworm


//*********************************************************
//* structs
//*********************************************************
// a worm structure
struct worm {
    int curl_lastindex; // current last index in the array of worms element positions
    int maxindex;       // Last usable index in the array pointed to by wormpos
    int headindex;      // An index in the array for the head position of the worm
                        // 0 <= headindex <= maxindex
    pos_t wormpos[WORM_LENGTH]; // Array of x,y positions of all the elements of the worm

    // The current heading of the worm
    // These are offsets from the set {-1, 0, +1}
    int dy;
    int dx;
    // color of the worm
    colorpairs_t wcolor;
};


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

typedef enum Boni {
    // additional length for worm when consuming food
    BONUS_1 = 2,
    BONUS_2 = 4,
    BONUS_3 = 6,
} boni_t;

// structs
typedef struct worm worm_t;

//*********************************************************
//* function prototypes
//*********************************************************
// Functions concerning the management of the worm data
rescodes_t initializeWorm(worm_t* aworm, int len_max, int len_cur, pos_t headpos, wormheading_t dir, colorpairs_t color);
void growWorm(worm_t* aworm, boni_t growth)

// show & delete worm elements
void showWorm(board_t* aboard, worm_t* aworm);
void cleanWormTail(board_t* aboard, worm_t* aworm);

// worm movement
void moveWorm(board_t* aboard, worm_t* aworm, gamestates_t* agame_state);

// collision detection
extern bool isInUseByWorm(worm_t* aworm, pos_t new_headpos);

// Setters
extern void setWormHeading(worm_t* aworm, wormheading_t dir);

// Getters
pos_t getWormHeadPos(worm_t* aworm);
int getWormLength(worm_t* aworm);

#endif  // #define _WORM_MODEL_H
