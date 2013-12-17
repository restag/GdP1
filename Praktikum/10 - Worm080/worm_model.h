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
 * The wormmodel contains the data needed for worm creation and modification
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
 *
 */


#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_model.h"
#include "display_model.h"


//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define WORM_INITIAL_LENGTH 4       // initial length of a new worm
#define WORM_UNUSED_POS_ELEMENT -1  // element for unused worm positions


//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum WormHeading {
	WORM_UP,
	WORM_DOWN,
	WORM_LEFT,
	WORM_RIGHT,
};


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum WormHeading wormheading_t;

//*********************************************************
//* structs
//*********************************************************
// put structs below here
// a worm structure
struct worm {
    int maxindex;       // Last usable index in the array pointed to by wormpos
    int headindex;      // An index in the array for the head position of the worm
                        // 0 <= headindex <= maxindex
    pos_t* wormpos;     // Array of x,y positions of all the elements of the worm

    // The current heading of the worm
    // These are offsets from the set {-1, 0, +1}
    pos_t nextStep;

    // color of the worm
    colorpairs_t wcolor;
};


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct worm worm_t;


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

//* model allocation
worm_t* allocWorm(void);
pos_t* allocWormposArray(worm_t* aWorm);

//* free model
void freeWorm(worm_t* aWorm);
void freeWormposArray(pos_t* wormposArray);

//* model setters
void setWormMaxindex(worm_t* aWorm, int maxindex);
void setWormHeadindex(worm_t* aWorm, int headindex);
void setWormposAtIndex(worm_t* aWorm, pos_t* aWormpos, int index);
void setWormNextStep(worm_t* aWorm, pos_t* aWormpos);
void setWormcolor(worm_t* aWorm, colorpairs_t aColor);

//* getters
int getWormMaxindex(worm_t* aWorm);
int getWormLength(worm_t* aWorm);
int getWormHeadindex(worm_t* aWorm);
pos_t* getWormposAtIndex(worm_t* aWorm, int index);
pos_t* getWormNextStep(worm_t* aWorm);
#endif  // #define _WORM_MODEL_H
