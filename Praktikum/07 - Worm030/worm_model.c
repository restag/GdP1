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

#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "worm_model.h"

// Data defining the worm
int theworm_wormpos_y[WORM_LENGTH]; // Array of y positions for worm elements
int theworm_wormpos_x[WORM_LENGTH]; // Array of x positions for worm elements
int theworm_maxindex;               // Last usable index in the arrays theworm_wormpos_y and theworm_wormpos_x
int theworm_headindex;              // an index in the array for the worm's head position 0<= theworm_headindex<= theworm_maxindex


// The current heading of the worm
// These are offsets from the set {-1,0,+1}
int theworm_dx;
int theworm_dy;

color_pairs_t theworm_wcolor;       // Code of color pair used for the worm




// *****************************************************
// Functions concerning the management of the worm data
// *****************************************************

// START WORM_DETAIL
// The following functions all depend on the model of the worm

// Initialize the worm
extern res_codes_t initializeWorm(int len_max, int headpos_y, int headpos_x, worm_heading_t dir, color_pairs_t color) {
    // Local vars for loops etc.
    int i;

    // initialize last usable index to len_max -1: theworm_maxindex
    theworm_maxindex = len_max - 1;
    
    //initialize headindex: theworm_headindex
    theworm_headindex = 0;

    /* Mark all elements as unused in the arrays of positions
     * theworm_wormpos_y[] and theworm_wormpos_x[]
     * an unused position in the array is marked with code UNUSED_POS_ELEM*/
    for (i=0; i<= theworm_maxindex;i++){
        theworm_wormpos_y[i] = UNUSED_POS_ELEM;
        theworm_wormpos_x[i] = UNUSED_POS_ELEM;
    }

    // Initialize position of worms head
    theworm_wormpos_y[theworm_headindex] = headpos_y;
    theworm_wormpos_x[theworm_headindex] = headpos_x;

    // Initialize the heading of the worm
    setWormHeading(dir); 

    // Initialze color of the worm
    theworm_wcolor = color;

    return RES_OK;
}


// Show the worms's elements on the display
// Simple version
extern void showWorm() {
    // Due to our encoding we just need to show the head element
    // All other elements are already displayed
    placeItem(theworm_wormpos_y[theworm_headindex], theworm_wormpos_x[theworm_headindex], SYMBOL_WORM_INNER_ELEMENT, theworm_wcolor);
}

extern void cleanWormTail() {

    int tailindex;

    // Compute tailindex
    tailindex = (theworm_headindex + 1) % WORM_LENGTH;

    // Check the array of worm elements.
    // Is the arrayelement at tailindex already in use?
    // Checking either array theworm_wormpos_y or theworm_wormpos_x is enough.
    if (theworm_wormpos_y[tailindex] != UNUSED_POS_ELEM) {

        // YES: place a SYMBOL_FREE_CELL at the tail's position
        placeItem(theworm_wormpos_y[tailindex], theworm_wormpos_x[tailindex], SYMBOL_FREE_CELL, COLP_FREE_CELL);

    }

}

extern void moveWorm(game_states_t* agame_state) {
    int headpos_y;
    int headpos_x;

    // get the current position of the worm's head element and
    // compute the new head position according to current heading.
    // DO NOT store the new head position in the array of positions, yet.
    headpos_y = theworm_wormpos_y[theworm_headindex] + theworm_dy;
    headpos_x = theworm_wormpos_x[theworm_headindex] + theworm_dx;

    // Check if we would hit something or are going to leave the display
    // if we move the worm's head according to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos_x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos_x > getLastCol() ) { 
        *agame_state = WORM_OUT_OF_BOUNDS; 
    } else if (headpos_y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos_y > getLastRow() ) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else {
        // We will stay within bounds.
        // Check if the worm's head will collide with itself at the new position
        if (isInUseByWorm(headpos_y, headpos_x)) {
            // bites itself: BAD => stop game
            *agame_state = WORM_CROSSING;
        }
    }

    if (*agame_state == WORM_GAME_ONGOING) {
        // all is good: we didn't hit anything or leave the display
        // => update the worm structure.
        // Increment theworm_headindex
        // Go round if end of worm is reached (ring buffer)

        if (theworm_headindex == WORM_LENGTH -1) {
            theworm_headindex = 0;
        } else {
            theworm_headindex++;
        }

        // store new coordinates of the head element into worm structure
        theworm_wormpos_x[theworm_headindex] = headpos_x;
        theworm_wormpos_y[theworm_headindex] = headpos_y;
    }
}

// a simple collision detection
extern bool isInUseByWorm(int new_headpos_y, int new_headpos_x) {
    int i;
    bool collision = false;
    
    // wirkt kurios
    i = theworm_headindex;
    do {
        // do some index magic
        if (i == WORM_LENGTH) {
            i = 0;
        } else {
            i++;
        }

        //compare the position of the current worm element with the new_headpos
        if (theworm_wormpos_x[i] == new_headpos_x && theworm_wormpos_y[i] == new_headpos_y){
            collision = true;
        }
    } while (i != theworm_headindex && theworm_wormpos_x[i-1] != UNUSED_POS_ELEM && !collision);


    // return result
    return collision;
}

// Setters
extern void setWormHeading(worm_heading_t dir) {
    switch(dir) {
        case WORM_UP :// User wants up
            theworm_dx= 0;
            theworm_dy= -1;
            break;
        case WORM_DOWN :// User wants down
            theworm_dx = 0;
            theworm_dy = 1;
            break;
        case WORM_LEFT      :// User wants left
            theworm_dx = -1;
            theworm_dy = 0;
            break;
        case WORM_RIGHT      :// User wants right
            theworm_dx = 1;
            theworm_dy = 0;
            break;
    }
}
