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
 * The messagearea_controller is used for messagearea interaction
 *
 * Tasks:
 *      * initialization
 *      * handling
 */

#ifndef _MESSAGEAREA_CONTROLLER_H
#define _MESSAGEAREA_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_model.h"
#include "messagearea_model.h"
#include "worm_model.h"

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

//* initialize module
messagearea_t* initializeMessagearea(void);

//* free module
void freeMessageareaAndContent(messagearea_t* aMessagearea);

//* module management
void moveMessageareaToIndex(messagearea_t* aMessagearea, int lineIndex);

//* module content management
void clearMessagelineInMessagearea(messagearea_t* aMessagearea, int lineNumber);
void setMessageAtLineWithString(messagearea_t* aMessagearea,int lineNumber, char* aString);
void setAllMessagesWithStrings(messagearea_t* aMessagearea, char* string1, char* string2, char* string3);

//* output management

//* display management
void printCompleteMessagearea(messagearea_t* aMessagearea);
void updateWormStatus(messagearea_t* aMessagearea, board_t* aBoard, worm_t* aWorm);
int printDialog(messagearea_t* aMessagearea, char* prompt1, char* prompt2);

//* display interaction
void fillMessagearealineWithSymbol(messagearea_t* aMessagearea, int lineNumber, char symbol);
void eraseMessageareaLineInDisplay(messagearea_t* aMessagearea, int lineNumber);
void printMessagelineToDisplay(messagearea_t* aMessagearea, int lineNumber);
void printStringToMessagearea(messagearea_t* aMessagearea, int lineNumber, char* aString);
void printMessageareaBorder(messagearea_t* Messagearea);
void removeMessageareaFromDisplay(messagearea_t* aMessagearea);

#endif  // #define _MESSAGEAREA_CONTROLLER_H
