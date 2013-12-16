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
 * Tasks:
 *      * Level initialization
 *      * run game
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>
#include <stdbool.h>

// put custom header includes below here
#include "game_controller.h"
#include "board_controller.h"
#include "userinteraction_controller.h"
#include "worm_controller.h"
#include "messagearea_controller.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initialize module
void initializeLevel(board_t* theBoard)
{
    // initialize barriers
    initializeBarriers(theBoard);

    // initialize fooditems
    initializeFoodItems(theBoard);
}

//*********************************************************
//* free module


//*********************************************************
//* module management
rescodes_t doLevel(board_t* theBoard, messagearea_t* theMessagearea, worm_t* theWorm)
{
    gamestates_t game_state;        // the current game state
    rescodes_t res_code;            // result code from functions

    bool end_level_loop;            // indicates whether we should leave the main loop

    worm_t* userworm = theWorm;     // the userworm


    // at the beginning we still have the chance to win
    game_state = WORM_GAME_ONGOING;

    // start the loop for this level
    end_level_loop = false;     // flag for controlling the main loop

    // main loop
    while(!end_level_loop)  {
        // process userinput
        readUserInput(userworm, & game_state);
        
        // quit when user presses 'q'
        if (game_state == WORM_GAME_QUIT) {
            end_level_loop = true;
            continue;           // got to beginning of the loop's block and check loop condition
        }

        // process userworm
        // clean the tail of the worm
        cleanWormTail(theBoard, userworm);

        // now move the worm for one step
        moveWorm(theBoard, userworm, &game_state);

        // quit when user crashed
        if (game_state == WORM_CRASH){
            end_level_loop = true;
            continue;
        }

        // quit when worm bit itself
        if (game_state == WORM_CROSSING){
            end_level_loop = true;
            continue;
        }

        // quit when no food items are left
        if (game_state == BOARD_NO_FOOD_LEFT){
            end_level_loop = true;
            continue;
        }

        // show the new Head
        showWorm(theBoard, userworm);

        // update messagearea
        updateWormStatus(theMessagearea, theBoard, userworm);

        // sleeptime
        napms(NAP_TIME);

        // display changes
        refresh();
    }

    // game worked fine, set recode to ok
    res_code = RES_OK;

    // print game summary
    switch (game_state){
        case WORM_CRASH:
            printDialog(theMessagearea, "Sie haben verloren!", "Sie sind in ein Hinderniss gefahren...");
            break;
        case WORM_CROSSING:
            printDialog(theMessagearea, "Sie haben verloren!", "Da war schon ein Wurm...");
            break;
        case WORM_GAME_QUIT:
            printDialog(theMessagearea, "Das Spiel wurde beendet.", NULL);
            break;
        case BOARD_NO_FOOD_LEFT:
            printDialog(theMessagearea, "Sie haben gewonnen!", "Es sind keine Futterbrocken uebrig");
            break;
        default:
            printDialog(theMessagearea, "Hier ist etwas schief gelaufen!", "Für diesen Fall liegt keine Meldung vor...");
    }

    // return the result code
    return res_code;
}

//*********************************************************
//* module content management


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
