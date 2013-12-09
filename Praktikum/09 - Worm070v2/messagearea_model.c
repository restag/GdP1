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
    return theMessageArea;
}

void freeMessageArea(messagearea_t* aMessageArea)
{
    // free content
    int i;

    for (i = 0; i < MESSAGEAREA_MIN_HEIGHT; i++) {
        freeMessage(aMessageArea -> messageLine[i]);
    }
    
    // free message area
    free(aMessageArea);
}

//* setters
void setMessageAtLine(messagearea_t* aMessageArea, message_t* aMessage, int lineNumber)
{
    aMessageArea -> messageLine[lineNumber - 1] = aMessage;
}

//*********************************************************
//* getters
message_t* getMessageFromLine(messagearea_t* aMessageArea, int lineNumber)
{
    return aMessageArea -> messageLine[lineNumber -1];
}
