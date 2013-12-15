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
 * The messagwmodel contains the data needed for
 * message creation and handling
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
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

//* model allocation
message_t* allocMessage(void);

//* free model
void freeMessage(message_t* aMessage);
void freeMsgString(char* aMsgString);

//* model setters
void setMsgString(message_t* aMessage, char* aString);

//* getters
char* getMsgString(message_t* aMessage);

#endif  // #define _<MODULE-NAME>_MODEL_H
