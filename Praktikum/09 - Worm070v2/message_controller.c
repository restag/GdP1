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

//*********************************************************
//* intitialize a message
message_t* initMessageWithString(char* aString)
{
    message_t* msg = initBlankMessage();

    setMsgString(msg, aString);

    return msg;
}

void alterMessage(message_t* aMessage, char* newString)
{
    setMsgString(aMessage, newString);
}
