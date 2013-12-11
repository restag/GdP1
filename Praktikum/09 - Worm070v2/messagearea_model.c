/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <stdlib.h>

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
//* allocation & freeing
messagearea_t* allocMessagearea(void)
{
    messagearea_t* theMessagearea = malloc(sizeof(messagearea_t));

    return theMessagearea;
}

void freeMessagearea(messagearea_t* theMessagearea)
{
    free(theMessagearea);
}

//*********************************************************
//* setters
void setMessageareaBaseIndex(messagearea_t* theMessagearea, int lineIndex)
{
    theMessagearea -> baseIndex = lineIndex;
}

void setMessagecode(messagearea_t* theMessagearea, messagecodes_t theMessagecode)
{
    theMessagearea -> messageCode = theMessagecode;
}

void setMessageAtLine(messagearea_t* theMessagearea, message_t* theMessage, int lineNumber)
{
    theMessagearea -> messageLine[lineNumber - 1] = theMessage;
}

//*********************************************************
//* getters
int getMessageareaBaseIndex(messagearea_t* theMessagearea)
{
    return theMessagearea -> baseIndex;
}

messagecodes_t getMessagecode(messagearea_t* theMessagearea)
{
    return theMessagearea -> messageCode;
}

message_t* getMessageFromLine(messagearea_t* theMessagearea, int lineNumber)
{
    return theMessagearea -> messageLine[lineNumber -1];
}
