/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************

//*********************************************************
//* setters
void setMsgLength(message_t* aMessage, int length)
{
    aMessage -> msgLength = length;
}

void setMsgString(message_t* aMessage, char* aString)
{
    aMessage -> msgString = aString;
}

//*********************************************************
//* getters

