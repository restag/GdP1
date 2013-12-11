/* put a description in here 
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

// management
void moveMessageareaToIndex(messagearea_t* aMessagearea, int lineIndex);

// display interaction
void eraseMessageLineInDisplay(messagearea_t* aMessagearea, int lineNumber);
void printMessageLine(messagearea_t* aMessageArea, int lineNumber);


/*
void clearLineInMessageArea(messagearea_t* aMessageArea, int lineNumber);
void clearMessageArea(messagearea_t* aMessageArea);

void printMessages(messagearea_t* aMessageArea);
void updateStatus(messagearea_t* aMessageArea, board_t* aBoard, worm_t* aWorm);
void setDialog(messagearea_t* aMessageArea, char* prompt1, char* prompt2);
int printDialog(messagearea_t* aMessageArea, char* prompt1, char* prompt2);
*/
#endif  // #define _MESSAGEAREA_CONTROLLER_H
