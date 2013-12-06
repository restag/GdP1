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
message_t createMsg(char[] string)
{
    int* p = malloc(sizeof(string +1));

    return 
