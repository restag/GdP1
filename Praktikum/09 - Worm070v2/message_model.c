/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

//*********************************************************
message_t* allocBlankMessage()
{
    // reserve memory
    message_t* newMsg = malloc(sizeof(message_t));
    
    // asign default Value
    newMsg -> msgString = NULL;

    return newMsg;

}

void freeMessage(message_t* aMessage)
{
    clearMsgString(aMessage);

    free(aMessage);
}

//* initializers

//* setters
void setMsgString(message_t* aMessage, char* aString)
{
    // free the old one
    clearMsgString(aMessage);

    // set the new one
    aMessage -> msgString = strdup(aString);
}

void clearMsgString(message_t* aMessage)
{
    // check if exists
    if (aMessage -> msgString != NULL) {
        free(aMessage -> msgString);
    }

}

//*********************************************************
//* getters

