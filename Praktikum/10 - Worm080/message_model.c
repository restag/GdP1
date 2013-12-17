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
 * The messagwmodel contains the data needed for
 * message creation and handling
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
#include <string.h>

// put custom header includes below here
#include "message_model.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* model allocation
message_t* allocMessage(void)
{
    message_t* newMessage = malloc(sizeof(message_t));

    return newMessage;
}

//*********************************************************
//* free model
void freeMessage(message_t* theMessage)
{
    if (theMessage != NULL) {
        // free self
        free(theMessage);
    }
}

void freeMsgString(char* theMsgString)
{
    if (theMsgString != NULL) {
        // free self
        free(theMsgString);
    }
}


//*********************************************************
//* setters
void setMsgMaxlength(message_t* theMessage, int maxlength)
{
    theMessage -> max_length = maxlength;
}

void setMsgString(message_t* theMessage, char* theString)
{
    if (theString != NULL) {
        theMessage -> msgString = strdup(theString);
    } else {
        theMessage -> msgString = NULL;
    }
}

//*********************************************************
//* getters
int getMsgMaxlength(message_t* theMessage)
{
    return theMessage -> max_length;
}

char* getMsgString(message_t* theMessage)
{
    return theMessage -> msgString;
}
