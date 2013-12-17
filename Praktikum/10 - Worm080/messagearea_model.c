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
void setMessageAtLine(messagearea_t* theMessagearea, message_t* theMessage, int lineNumber)
{
    if (theMessage != NULL) {
        theMessagearea -> messageLine[lineNumber - 1] = theMessage;
    } else {
        theMessagearea -> messageLine[lineNumber - 1] = NULL;
    }
}


//*********************************************************
//* getters
message_t* getMessageFromLine(messagearea_t* theMessagearea, int lineNumber)
{
    return theMessagearea -> messageLine[lineNumber -1];
}
