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
#include <string.h>
#include <stdlib.h>

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
//* allocation & freeing
message_t* allocMessage(void)
{
    message_t* newMessage = malloc(sizeof(message_t));

    return newMessage;
}

void freeMessage(message_t* theMessage)
{
    if (theMessage != NULL) {
        free(theMessage);
    }
}

void freeMsgString(char* theMsgString)
{
    if (theMsgString != NULL) {
        free(theMsgString);
    }
}


//* setters
void setMsgString(message_t* theMessage, char* aString)
{
    if (aString != NULL) {
        theMessage -> msgString = strdup(aString);
    } else {
        theMessage -> msgString = NULL;
    }
}


//*********************************************************
//* getters
char* getMsgString(message_t* theMessage)
{
    return theMessage -> msgString;
}
