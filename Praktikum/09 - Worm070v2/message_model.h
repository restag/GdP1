/* put a description in here 
 *
 */

#ifndef _MESSAGE_MODEL_H
#define _MESSAGE_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here


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
struct Message {
    int msgLength;
    char* msgString;
};

//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct Message message_t;

//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

// setters
void setMsgLength(message_t* aMessage, int length);
void setMsgString(message_t* aMessage, char* aString);

// getters
#endif  // #define _MESSAGE_MODEL_H
