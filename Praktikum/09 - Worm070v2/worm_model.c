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

//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_model.h"

//*********************************************************
//* global vars
//*********************************************************



//*********************************************************
//* fuctions
//*********************************************************
// Setters
void setWormHeading(worm_t* aworm, wormheading_t dir)
{
    switch(dir) {
        case WORM_UP :// User wants up
            aworm -> dx= 0;
            aworm -> dy= -1;
            break;
        case WORM_DOWN :// User wants down
            aworm -> dx = 0;
            aworm -> dy = 1;
            break;
        case WORM_LEFT      :// User wants left
            aworm -> dx = -1;
            aworm -> dy = 0;
            break;
        case WORM_RIGHT      :// User wants right
            aworm -> dx = 1;
            aworm -> dy = 0;
            break;
    }
}

// Getters
extern pos_t getWormHeadPos(worm_t* aworm)
{
    // structures are passed by value!
    // -> we return a copy here
    return aworm -> wormpos[aworm -> headindex];


}

int getWormLength(worm_t* aworm)
{
    return aworm -> cur_lastindex;
}
