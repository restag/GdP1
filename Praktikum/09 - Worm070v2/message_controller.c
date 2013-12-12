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
#include <stdlib.h>

// put custom header includes below here
#include "message_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here
//*********************************************************
//* initializing & freeing
message_t* initializeMessage()
{
    // reserve memory
    message_t* newMessage = allocMessage();

    // asign default value
    setMsgString(newMessage, NULL);

    return newMessage;
}

message_t* initializeMessageWithString(char* newString)
{
    message_t* newMessage = initializeMessage();
    
    alterMessage(newMessage, newString);

    return newMessage;
}

void freeMessageAndContent(message_t* theMessage)
{
    // free content
    freeMsgString(theMessage -> msgString);

    // free message
    freeMessage(theMessage);
}


//*********************************************************
//* management
void alterMessage(message_t* theMessage, char* newString)
{
    // check if exists
    if (theMessage -> msgString != NULL) {
        //free the old one
        freeMsgString(theMessage -> msgString);
    }
    
    // set the new one
    setMsgString(theMessage, newString);
}
