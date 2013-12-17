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
 * The messageareamodel contains the data needed for
 * messagearea creation and handling
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
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
//* model allocation
messagearea_t* allocMessagearea(void)
{
    messagearea_t* newMessagearea = malloc(sizeof(messagearea_t));

    return newMessagearea;
}


//*********************************************************
//* free model
void freeMessagearea(messagearea_t* theMessagearea)
{
    free(theMessagearea);
}


//*********************************************************
//* setters
void setMessageareaBaseindex(messagearea_t* theMessagearea, int baseindex)
{
    theMessagearea -> baseindex = baseindex;
}

void setMessageareaMessagecode(messagearea_t* theMessagearea, messagecodes_t theMessagecode)
{
    theMessagearea -> messagecode = theMessagecode;
}

void setMessageAtIndex(messagearea_t* theMessagearea, message_t* theMessage, int lineIndex)
{
    if (theMessage != NULL) {
        theMessagearea -> messageLine[lineIndex] = theMessage;
    } else {
        theMessagearea -> messageLine[lineIndex] = NULL;
    }
}

void setMessageAtLine(messagearea_t* theMessagearea, message_t* theMessage, int lineNumber)
{
    setMessageAtIndex(theMessagearea, theMessage, lineNumber - 1);
}


//*********************************************************
//* getters
int getMessageareaBaseindex(messagearea_t* theMessagearea)
{
    return theMessagearea -> baseindex;
}

messagecodes_t getMessageareaMessagecode(messagearea_t* theMessagearea)
{
    return theMessagearea -> messagecode;
}

message_t* getMessageFromIndex(messagearea_t* theMessagearea, int lineIndex)
{
    return theMessagearea -> messageLine[lineIndex];
}

message_t* getMessageFromLine(messagearea_t* theMessagearea, int lineNumber)
{
    return getMessageFromIndex(theMessagearea, lineNumber -1);
}
