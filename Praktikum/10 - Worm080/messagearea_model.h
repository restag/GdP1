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
 * The messageareamodel contains the data needed for
 * messagearea creation and handling
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
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
// dimensions
#define MESSAGEAREA_MAX_MESSAGES 3
#define MESSAGEAREA_BLANKS_RESERVED_LEFT 1
#define MESSAGEAREA_BLANKS_RESERVED_RIGHT 1
#define MESSAGEAREA_MIN_HEIGHT (MESSAGEAREA_MAX_MESSAGES + 2)

// symbols
#define SYMBOL_MESSAGEAREA_BORDER '*'


//*********************************************************
//* enums
//*********************************************************
// put enums below here
enum MessageCodes {
    MC_ERROR,
    MC_STATUS,
    MC_WON,
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
    int baseindex;
    messagecodes_t messagecode;
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

//* model allocation
messagearea_t* allocMessagearea(void);

//* free model
void freeMessagearea(messagearea_t* aMessagearea);

//* model setters
void setMessageareaBaseindex(messagearea_t* aMessagearea, int baseindex);
void setMessageareaMessagecode(messagearea_t* aMessagearea, messagecodes_t aMessagecode);
void setMessageAtIndex(messagearea_t* aMessagearea, message_t* aMessage, int lineIndex);
void setMessageAtLine(messagearea_t* aMessagearea, message_t* aMessage, int lineNumber);

//* getters
int getMessageareaBaseindex(messagearea_t* aMessagearea);
messagecodes_t getMessageareaMessagecode(messagearea_t* aMessagearea);
message_t* getMessageAtIndex(messagearea_t* aMessagearea, int lineIndex);
message_t* getMessageAtLine(messagearea_t* aMessagearea, int lineNumber);

#endif  // #define _MESSAGEAREA_MODEL_H
