/* put a description in here 
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// include framework headers below here
#include <stdio.h>

// include headers below here
#include "gameops.h"
#include "prep.h"


//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main(void) {
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
