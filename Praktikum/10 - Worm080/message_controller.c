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
 * The messagecontroller is used for message interaction
 *
 * Tasks:
 *      * initialization
 *      * handling
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <string.h>

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
//* initialize module
message_t* initializeMessageWithString(char* theString)
{
    // reserve memory
    message_t* newMessage = allocMessage();

    // set message string
    setMsgString(newMessage, theString);

    // return pointer
    return newMessage;
}

//*********************************************************
//* free module
void freeMessageAndContent(message_t* theMessage)
{
    if (theMessage != NULL){
        // free content
        freeMsgString(theMessage -> msgString);

        // free message
        freeMessage(theMessage);
    }
}

//*********************************************************
//* module management


//*********************************************************
//* module content management


//*********************************************************
//* output management


//*********************************************************
//* display management


//*********************************************************
//* display interaction
