/* put a description in here 
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
message_t* createMessage()
{
    message_t* theMessage = allocBlankMessage();

    return theMessage;
}

message_t* createMessageWithString(char* newString)
{
    message_t* newMessage = createMessage();
    
    alterMessage(newMessage, newString);

    return newMessage;
}

void alterMessage(message_t* aMessage, char* newString)
{
    setMsgString(aMessage, newString);
}
