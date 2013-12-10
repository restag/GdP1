/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <stdlib.h>

// put custom header includes below here
#include "messagearea_model.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* program main

//*********************************************************

messagearea_t* allocBlankMessageArea()
{
    messagearea_t* theMessageArea = malloc(sizeof(messagearea_t));
    int lineIndex;
    
    for (lineIndex = 0; lineIndex < MESSAGEAREA_MIN_HEIGHT - 1; lineIndex++) {
        theMessageArea -> messageLine[lineIndex] = NULL;
    }
    return theMessageArea;
}

void freeMessageArea(messagearea_t* aMessageArea)
{
    // free content
    int i;

    for (i = 1; i < MESSAGEAREA_MIN_HEIGHT; i++) {
        freeMessageLine(aMessageArea, i);
    }
    
    // free message area
    free(aMessageArea);
}

void freeMessageLine(messagearea_t* theMessageArea, int lineNumber)
{
    freeMessage(theMessageArea -> messageLine[lineNumber]);
}

//* setters
void setMessageAtLine(messagearea_t* theMessageArea, message_t* theMessage, int lineNumber)
{
    theMessageArea -> messageLine[lineNumber - 1] = theMessage;
}

//*********************************************************
//* getters
message_t* getMessageFromLine(messagearea_t* aMessageArea, int lineNumber)
{
    return aMessageArea -> messageLine[lineNumber -1];
}
