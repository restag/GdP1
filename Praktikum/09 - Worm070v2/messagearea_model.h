/* put a description in here 
 *
 */

#ifndef _MESSAGEAREA_H
#define _MESSAGEAREA_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define MESSAGEAREA_MIN_HEIGHT 4

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
    int height;
    char* messageLine[MESSAGEAREA_MIN_HEIGHT - 1];
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

// setters
void setMessageAtLine(messagearea_t* aMessageArea, char* aMessageText, int lineNumber);

// getters
char* getMessageFromLine(messagearea_t* aMessageArea, int lineNumber);

#endif  // #define _MESSAGE_H
