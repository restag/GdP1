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
#include <stdbool.h>

// include custom headers below here
#include "gameops.h"
#include "worm_model.h"
#include "board_model.h"
#include "userops.h"

//*********************************************************
//* fuctions
//*********************************************************
// game management
rescodes_t doLevel()
{
    gamestates_t game_state; // The current game_state

    rescodes_t res_code; // Result code from functions
    bool end_level_loop;    // Indicates whether we should leave the main loop

    worm_t userworm;    // the userworm
    pos_t bottomLeft;   // Start positions of the worm

    // At the beginning of the level, we still have a chance to win
    game_state = WORM_GAME_ONGOING;

    // There is always an initialized user worm.
    // Initialize the userworm with its size, position, heading.
    bottomLeft.y =  getLastRow();
    bottomLeft.x =  0;

    res_code = initializeWorm(&userworm, WORM_LENGTH, bottomLeft, WORM_RIGHT, COLP_USER_WORM);
    if ( res_code != RES_OK) {
        return res_code;
    }

    // Show worm at its initial position
    showWorm(&userworm);

    // Display all what we have set up until now
    refresh();

    // Start the loop for this level
    end_level_loop = false; // Flag for controlling the main loop
    while(!end_level_loop) {
        // Process optional user input
        readUserInput(&userworm, &game_state); 
        if ( game_state == WORM_GAME_QUIT ) {
            end_level_loop = true;
            continue; // Go to beginning of the loop's block and check loop condition
        }


        // Process userworm
        // Clean the tail of the worm
        cleanWormTail(&userworm);

        // Now move the worm for one step
        moveWorm(&userworm, &game_state);
        
        // Bail out of the loop if something bad happened
        if (game_state != WORM_GAME_ONGOING) {
            end_level_loop = true;
            continue; // Go to beginning of the loop's block and check loop condition
        }
        // Show the worm at its new position
        showWorm(&userworm);
        // END process userworm

        // Sleep a bit before we show the updated window
        napms(NAP_TIME);

        // Display all the updates
        refresh();

        // Start next iteration
    }

    // Preset res_code for rest of the function
    res_code = RES_OK;

    // For some reason we left the control loop of the current level.
    // However, in this version we do not yet check for the reason.
    // There is no user feedback at the moment!

    // Normal exit point
    return res_code;
}
