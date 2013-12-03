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
// include framework headers below here

// include headers below here
#include "worm_model.h"

//*********************************************************
//* global vars
//*********************************************************



//*********************************************************
//* fuctions
//*********************************************************
//* worm data management
// Initialize the worm
rescodes_t initializeWorm(worm_t* aworm, int len_max, pos_t headpos, wormheading_t dir, colorpairs_t color) {
    // Local vars for loops etc.
    int i;

    // initialize last usable index to len_max -1: aworm.maxindex
    aworm -> maxindex = len_max - 1;
    
    //initialize headindex: aworm.headindex
    aworm -> headindex = 0;

    /* Mark all elements as unused in the arrays of positions
     * aworm.wormpos[]
     * an unused position in the array is marked with code UNUSED_POS_ELEM*/
    for (i=0; i<= aworm -> maxindex;i++){
        aworm -> wormpos[i].y = UNUSED_POS_ELEM;
        aworm -> wormpos[i].x = UNUSED_POS_ELEM;
    }

    // Initialize position of worms head
    aworm -> wormpos[aworm -> headindex] = headpos;

    // Initialize the heading of the worm
    setWormHeading(aworm, dir); 

    // Initialze color of the worm
    aworm -> wcolor = color;

    return RES_OK;
}

// Show and delete the worms's elements on the display
void showWorm(worm_t* aworm) {
    // Due to our encoding we just need to show the head element
    // All other elements are already displayed
    placeItem(aworm -> wormpos[aworm -> headindex], SYMBOL_WORM_INNER_ELEMENT, aworm -> wcolor);
}

void cleanWormTail(worm_t* aworm) {

    int tailindex;

    // Compute tailindex
    tailindex = (aworm -> headindex + 1) % WORM_LENGTH;

    // Check the array of worm elements.
    // Is the arrayelement at tailindex already in use?
    // Checking either aworm -> wormpos.y or aworm -> wormpos.x is enough.
    if (aworm -> wormpos[tailindex].y != UNUSED_POS_ELEM) {

        // YES: place a SYMBOL_FREE_CELL at the tail's position
        placeItem( aworm -> wormpos[tailindex], SYMBOL_FREE_CELL, COLP_FREE_CELL);

    }

}

// worm movement
void moveWorm(worm_t* aworm, gamestates_t *agame_state) {
    pos_t headpos;

    // get the current position of the worm's head element and
    // compute the new head position according to current heading.
    // DO NOT store the new head position in the array of positions, yet.
    headpos.y = aworm -> wormpos[aworm -> headindex].y + aworm -> dy;
    headpos.x = aworm -> wormpos[aworm -> headindex].x + aworm -> dx;

    // Check if we would hit something or are going to leave the display
    // if we move the worm's head according to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos.x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastCol() ) { 
        *agame_state = WORM_OUT_OF_BOUNDS; 
    } else if (headpos.y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y > getLastRow() ) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else {
        // We will stay within bounds.
        // Check if the worm's head will collide with itself at the new position
        if (isInUseByWorm(aworm, headpos)) {
            // bites itself: BAD => stop game
            *agame_state = WORM_CROSSING;
        }
    }

    if (*agame_state == WORM_GAME_ONGOING) {
        // all is good: we didn't hit anything or leave the display
        // => update the worm structure.
        // Increment aworm -> headindex
        // Go round if end of worm is reached (ring buffer)

        if (aworm -> headindex == WORM_LENGTH -1) {
            aworm -> headindex = 0;
        } else {
            aworm -> headindex++;
        }

        // store new coordinates of the head element into worm structure
        aworm -> wormpos[aworm -> headindex] = headpos;
    }
}

// collision detection
bool isInUseByWorm(worm_t* aworm, pos_t new_headpos) {
    int i;
    bool collision = false;
    
    // wirkt kurios
    i = aworm -> headindex;
    do {
        //compare the position of the current worm element with the new_headpos
        if (aworm -> wormpos[i].x == new_headpos.x && aworm -> wormpos[i].y == new_headpos.y){
            collision = true;
        }
        
        // do some index magic
        if (i == WORM_LENGTH) {
            i = 0;
        } else {
            i++;
        }
    } while (i != aworm -> headindex && aworm -> wormpos[i-1].x != UNUSED_POS_ELEM && !collision);


    // return result
    return collision;
}

// Setters
extern void setWormHeading(worm_t* aworm, wormheading_t dir) {
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
pos_t getWormHeadPos(worm_t* aworm)
{
    // structures are passed by value!
    // -> we return a copy here
    return aworm -> wormpos[aworm -> headindex];


}
