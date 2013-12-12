/* put a description in here 
 *
 */

#ifndef _MESSAGE_CONTROLLER_H
#define _MESSAGE_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "message_model.h"

//*********************************************************
//* defines
//*********************************************************
// put defines below here


//*********************************************************
//* enums
//*********************************************************
// put enums below here


//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here


//*********************************************************
//* structs
//*********************************************************
// put structs below here


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here
// initalizing & freeing
message_t* initializeMessage(void);
message_t* initializeMessageWithString(char* aString);
void freeMessageAndContent(message_t* aMessage);




void alterMessage(message_t* aMessage, char* newString);
// setters

// getters
#endif  // #define _MESSAGE_CONTROLLER_H
