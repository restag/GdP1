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
#include <stdio.h>

// include headers below here
//#include "debug.h"  // uncomment for debugging
#include "gameops.h"
#include "prep.h"


//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main(void) {

    // stops program to make time to attach gdb
    #ifdef _DEBUG_H
    waitForUserInput();
    #endif



    rescodes_t res_code;         // Result code from functions

    // Here we start
    initializeCursesApplication();  // Init various settings of our application
    initializeColors();             // Init colors used in the game

    

    // Check if the window is large enough to display messages in the message area
    // a has space for at least one line for the worm
    if (!windowHasMinSize()) {
        // Since we not even have the space for displaying messages
        // we print a conventional error message via printf after
        // the call of cleanupCursesApp()
        cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n", MIN_NUMBER_OF_COLS, MIN_NUMBER_OF_ROWS );
        res_code = RES_FAILED;
    } else {
        res_code = doLevel();
        cleanupCursesApp();
    }

    return res_code;
}
