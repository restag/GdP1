/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>

// put custom header includes below here
#include "messagearea_controller.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* update worm status
void updateWormStatus(messagearea_t* aMessageArea, worm_t* aworm)
{
    aMessageArea -> messageLine[1] = 


}

//* clear line of message area

void clearLineInMessageArea(messagearea_t* aMessageArea, int lineNumber)
{
    int i;

    move(lineNumber, 0);
    for (i = 1; i<= COLS; i++) {
        addch(' ');
    }

    setMessageAtLine(aMessageArea, NULL, lineNumber);

}


