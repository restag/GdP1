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

// put custom header includes below here
//#include "prep.h"
#include "board_model.h"

//*********************************************************
//* defines
//*********************************************************
#define WORM_LENGTH (BOARD_MIN_HEIGHT * BOARD_MIN_WIDTH)          // Maximal length of the worm
#define WORM_INITIAL_LENGTH 4   // initial length of the userworm


//*********************************************************
//* structs
//*********************************************************
// a worm structure
struct worm {
    int cur_lastindex; // current last index in the array of worms element positions
    int maxindex;       // Last usable index in the array pointed to by wormpos
    int headindex;      // An index in the array for the head position of the worm
                        // 0 <= headindex <= maxindex
    pos_t wormpos[WORM_LENGTH]; // Array of x,y positions of all the elements of the worm

    // The current heading of the worm
    // These are offsets from the set {-1, 0, +1}
    pos_t nextStep;

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


// structs
typedef struct worm worm_t;

//*********************************************************
//* function prototypes
//*********************************************************
// put function prototypes here
//*********************************************************
//* allocating & freeing
worm_t* allocWorm(void);
void freeWorm(worm_t* aWorm);

// Setters
void setCurLastIndex(worm_t* aWorm, int lastindex);
void setMaxIndex(worm_t* aWorm, int maxindex);
void setHeadIndex(worm_t* aWorm, int headindex);
void setWormpos(worm_t* aWorm, pos_t wormpos);
void setNextStep(worm_t* aWorm, pos_t nextStep);
void setWormColor(worm_t* aWorm, colorpairs_t wcolor);

// Getters
int getCurLastIndex(worm_t* aWorm);
int getMaxIndex(worm_t* aWorm);
int getHeadindex(worm_t* aWorm);
pos_t getWormposAtIndex(worm_t* aWorm, int index);
pos_t getNextStep(worm_t* aWorm);
pos_t getWormHeadpos(worm_t* aWorm);
int getWormLength(worm_t* aWorm);

#endif  // #define _WORM_MODEL_H
