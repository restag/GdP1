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
// allocation & freeing
message_t* allocMessage(void);
void freeMessage(message_t* aMessage);
void freeMsgString(char* aMsgString);

// setters
void setMsgString(message_t* aMessage, char* aString);

// getters
char* getMsgString(message_t* aMessage);
#endif  // #define _MESSAGE_MODEL_H
