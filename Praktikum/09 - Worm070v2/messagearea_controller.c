/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>
#include <stdio.h>
#include <string.h>

// put custom header includes below here
#include "messagearea_controller.h"
//#include "message_controller.h"
//#include "game_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initializing & freeing
messagearea_t* initializeMessagearea(void)
{
    // reserve memory
    messagearea_t* newMessagearea = allocMessagearea();

    // fill with default messages
    int i;
    for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++) {
        // assign default message value
        newMessagearea -> messageLine[i] = NULL;
    }

    // set to default position
    setMessageareaBaseIndex(newMessagearea, 0);
    newMessagearea -> baseIndex = 0;

    return newMessagearea;
}

void freeMessageareaAndContent(messagearea_t* theMessagearea)
{
    // free the content
    int i;
    for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++){
        if (theMessagearea -> messageLine[i] != NULL) {
            freeMessageAndContent(theMessagearea -> messageLine[i]);
        }
    }
    
    // free the messagearea
    freeMessagearea(theMessagearea);
}

//*********************************************************
//* management
void moveMessageareaToIndex(messagearea_t* theMessagearea, int lineIndex)
{
    setMessageareaBaseIndex(theMessagearea, lineIndex);
}

//*********************************************************
//* display interaction
void eraseMessageLineInDisplay(messagearea_t* theMessagearea, int lineNumber)
{
    int i;

    move(theMessagearea -> baseIndex + lineNumber, 0);

    for (i = 1; i <= COLS; i++) {
        addch(' ');
    }
}

void printMessageLine(messagearea_t* theMessagearea, int lineNumber)
{
    mvaddstr(theMessagearea -> baseIndex + lineNumber, 1, theMessagearea -> messageLine[lineNumber] -> msgString);
}

/*

void clearLineInMessageArea(messagearea_t* theMessageArea, int lineNumber)
{
    // free
    freeMessageLine(theMessageArea, lineNumber);

    // set blank
    theMessageArea -> messageLine[lineNumber - 1] = NULL;

    // clear at display
    eraseMessageLineInDisplay(lineNumber);    
}

void clearMessageArea(messagearea_t* theMessageArea)
{
    int i;

    for (i = 0; i < MESSAGEAREA_MIN_HEIGHT; i++) {
        clearLineInMessageArea(theMessageArea, i);
    }
}




void printMessages(messagearea_t* theMessageArea)
{
    int i;
    for (i = 1; i <= MESSAGEAREA_MIN_HEIGHT; i++){
        eraseMessageLineInDisplay(i);

        if (theMessageArea -> messageLine[i - 1] != NULL){
            printMessageLine(theMessageArea, i);
        }
    }
}

void updateStatus(messagearea_t* theMessageArea, board_t* theBoard, worm_t* theWorm)
{

    char baseString1[] = "Anzahl verbleibender Futterbrocken: %2d";
    char baseString2[] = "Der Wurm ist an Position: x= %3d y=%3d";
    char baseString3[] = "Länge des Wurms: %3d";

    char buff1[strlen(baseString1) + 1];
    char buff2[strlen(baseString2) + 1];
    char buff3[strlen(baseString3) + 1];

    pos_t headpos = getWormHeadPos(theWorm);

    sprintf(buff1, baseString1, getNumberOfFoodItems(theBoard));
    sprintf(buff2, baseString2, headpos.x, headpos.y);
    sprintf(buff3, baseString3, getWormLength(theWorm));

    setMessageAtLine(theMessageArea, createMessageWithString(buff1), 1);
    setMessageAtLine(theMessageArea, createMessageWithString(buff2), 2);
    setMessageAtLine(theMessageArea, createMessageWithString(buff3), 3);
}

void setDialog(messagearea_t* theMessageArea, char* prompt1, char* prompt2)
{
    clearMessageArea(theMessageArea);

    setMessageAtLine(theMessageArea, createMessageWithString(prompt1), 1);
    setMessageAtLine(theMessageArea, createMessageWithString(prompt2), 2);
}

int printDialog(messagearea_t* theMessageArea, char* prompt1, char* prompt2)
{
    if (prompt1 == NULL) {
        return RES_FAILED;
    }

    setDialog(theMessageArea, prompt1, prompt2);
    printMessages(theMessageArea);

    refresh();

    nodelay(stdscr, FALSE);
    int ch = getch();   // wait for user to press a key
    nodelay(stdscr, TRUE);

    clearMessageArea(theMessageArea);

    refresh();

    return ch;
}*/
