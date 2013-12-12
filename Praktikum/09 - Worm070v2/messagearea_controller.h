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

#ifndef _MESSAGEAREA_CONTROLLER_H
#define _MESSAGEAREA_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "messagearea_model.h"
#include "worm_model.h"
#include "board_model.h"


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
// initializing & freeing
messagearea_t* initializeMessagearea(void);
void freeMessageareaAndContent(messagearea_t* aMessagearea);

// area management
void moveMessageareaToIndex(messagearea_t* aMessagearea, int lineIndex);

// content management
void clearLineInMessagearea(messagearea_t* aMessagearea, int lineNumber);
void setAllMessagesWithStrings(messagearea_t* aMessagearea, char* string1, char* string2, char* string3);

// prepping for output
void updateWormStatus(messagearea_t* aMessagearea, board_t* aBoard, worm_t* aWorm);

// display management
void printMessagearea(messagearea_t* aMessagearea);
int printDialog(messagearea_t* aMessagearea, char* prompt1, char* prompt2, char* prompt3);

// display interaction
void eraseMessagelineInDisplay(messagearea_t* aMessagearea, int lineNumber);
void printMessageline(messagearea_t* aMessagearea, int lineNumber);

#endif  // #define _MESSAGEAREA_CONTROLLER_H
