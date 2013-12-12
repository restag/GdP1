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
//* allocation & freeing
message_t* allocMessage(void)
{
    message_t* newMessage = malloc(sizeof(message_t));

    return newMessage;
}

void freeMessage(message_t* theMessage)
{
    freeMsgString(theMessage -> msgString);

    free(theMessage);
}

void freeMsgString(char* theMsgString)
{
    free(theMsgString);
}


//* setters
void setMsgString(message_t* theMessage, char* aString)
{
    theMessage -> msgString = strdup(aString);
}


//*********************************************************
//* getters
char* getMsgString(message_t* theMessage)
{
    return theMessage -> msgString;
}
