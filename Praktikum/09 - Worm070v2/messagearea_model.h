/* A simple variant of the game Snake
 * Used for teaching in classes
 *
 * This version is an alternativ version of the given code,
 * following a more strict approach of separation
 *
 *
 * Author:
 * Benjamin Ewert
 * (c) 2013
 *
 * Author of original version:
 * Franz Regensburger
 * Ingolstadt University of Applied Sciences
 * (C) 2011
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
#define MESSAGEAREA_MAX_MESSAGES 3
#define MESSAGEAREA_BLANKS_RESERVED_LEFT 1
#define MESSAGEAREA_BLANKS_RESERVED_RIGHT 1


//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum MessageCodes {
    MC_STATUS,
    MC_WON,
    MC_ERROR,
};

//*********************************************************
//* enum type definitions
//*********************************************************
// put typedefs for enums here
typedef enum MessageCodes messagecodes_t;

//*********************************************************
//* structs
//*********************************************************
// put structs below here
struct MessageArea {
    int baseIndex;
    messagecodes_t messageCode;
    message_t* messageLine[MESSAGEAREA_MAX_MESSAGES];
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
// allocation & freeing
messagearea_t* allocMessagearea(void);
void freeMessagearea(messagearea_t* aMessagearea);

// setters
void setMessageareaBaseIndex(messagearea_t* aMessagearea, int lineIndex);
void setMessagecode(messagearea_t* aMessagearea, messagecodes_t aMessagecode);
void setMessageAtLine(messagearea_t* aMessagearea, message_t* aMessage, int lineNumber);

// getters
int getMessageareaBaseIndex(messagearea_t* aMessagearea);
messagecodes_t getMessagecode(messagearea_t* aMessagearea);
message_t* getMessageAtLine(messagearea_t* aMessagearea, int lineNumber);

#endif  // #define _MESSAGEAREA_MODEL_H
