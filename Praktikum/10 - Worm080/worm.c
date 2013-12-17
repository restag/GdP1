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
#include <stdio.h>

// put custom header includes below here
#include "worm.h"
#include "board_model.h"
#include "display_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* program main
int main()
{
    // initialize curses
    initializeCursesApp();  

    //* starting point for wormApp
    // result code from functions
    rescodes_t res_code;

    // * pregame checks
    // check the window dimesions
    if (windowCanContainMessagearea()){
        // do visual setup
        //initializeColors();
        //messagearea_t* theMessagearea = initializeMessagearea();
        
        // check if game can be run
        if (windowCanContainMessageareaAndBoard()){
            // all good, do pre-game setup
            //moveMessageareaToIndex(theMessagearea, BOARD_MIN_HEIGHT);

            // initialize the gameboard
           // board_t* theBoard = initializeBoard();
            //worm_t* userworm = initializeUserWorm(theBoard);
            //initializeLevel(theBoard);
            //refreshDisplay();




            // run game
            //res_code = doLevel(theBoard, theMessagearea, userworm);
        } else {
            // window too small for gameboard
            // print the Messagearea
            //printDialog(theMessagearea, "Das Fenster ist zu klein!", NULL);

            // set rescode
            res_code = RES_FAILED;
        }

        // cleanup Display
        cleanupCursesApp();
    } else {
        // the window is net even big enough to fit the message area
        // so we print a message to the terminal and set the resultcode
        // to failed
        cleanupCursesApp();
        //printf("Das Fenster ist zu klein! Wir brauchen mindestens %dx%d\n", BOARD_MIN_WIDTH, WINDOW_MIN_HEIGHT);
        puts("window is too small for messagearea");
        res_code = RES_FAILED;
    }
    
    // return rescode
    return res_code;
}
