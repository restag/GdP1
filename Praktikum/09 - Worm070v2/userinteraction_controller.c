/* put a description in here 
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "userinteraction_controller.h"
#include "worm_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* user input
void readUserInput(worm_t* aworm, gamestates_t* agame_state)
{
    int ch; // For storing the key codes

    if ((ch = getch()) > 0) {
        // Is there some user input?
        // Blocking or non-blocking depends of config of getch
        switch(ch) {
            case 'q' :    // User wants to end the show
                *agame_state = WORM_GAME_QUIT;
                break;
            case KEY_UP :// User wants up
                setWormHeading(aworm, WORM_UP);
                break;
            case KEY_DOWN :// User wants down
                setWormHeading(aworm, WORM_DOWN); 
                break;
            case KEY_LEFT :// User wants left
                setWormHeading(aworm, WORM_LEFT);
                break;
            case KEY_RIGHT :// User wants right
                setWormHeading(aworm, WORM_RIGHT);
                break;
            case 's' : // User wants single step
                nodelay(stdscr, FALSE);  // We simply make getch blocking
                break;
            case ' ' : // Terminate single step; make getch non-blocking again
                nodelay(stdscr, TRUE);   // Make getch non-blocking again
                break;
        }
    }
    return;
}
