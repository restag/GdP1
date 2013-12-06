/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

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
//* setters
void setMessageAtLine(messagearea_t* aMessageArea, char* aMessageText, int lineNumber)
{
    aMessageArea -> messageLine[lineNumber -1] = aMessageText;    
}

//*********************************************************
//* getters
char* getMessageFromLine(messagearea_t* aMessageArea, int lineNumber)
{
    return aMessageArea -> messageLine[lineNumber - 1];
}
