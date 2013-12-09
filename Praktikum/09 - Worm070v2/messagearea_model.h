/* put a description in here 
 *
 */

#ifndef _MESSAGEAREA_MODEL_H
#define _MESSAGEAREA_MODEL_H
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
#define MESSAGEAREA_MIN_HEIGHT 4
#define MESSAGEAREA_BLANKS_RESERVED_LEFT 1
#define MESSAGEAREA_BLANKS_RESERVED_RIGHT 1


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
struct MessageArea {
    message_t* messageLine[MESSAGEAREA_MIN_HEIGHT - 1];
};


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct MessageArea messagearea_t;


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

messagearea_t* allocBlankMessageArea();
void freeMessageArea(messagearea_t* aMessageArea);

// setters
void setMessageatLine(messagearea_t* aMessageArea, message_t* aMessage, int lineNumber);

// getters
message_t* getMessageFromLine(messagearea_t* aMessageArea, int lineNumber);

#endif  // #define _MESSAGEAREA_MODEL_H
