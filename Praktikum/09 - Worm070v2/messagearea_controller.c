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


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// put custom header includes below here
#include "messagearea_controller.h"
#include "display_controller.h"
#include "game_controller.h"
#include "message_controller.h"
#include "worm_controller.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* initialize module
messagearea_t* initializeMessagearea(void)
{
    // reserve memory
    messagearea_t* newMessagearea = allocMessagearea();

    // set default values
    setMessageareaBaseIndex(newMessagearea, 0);
    setMessagecode(newMessagearea, MC_STATUS);

    int i;
    for (i = 1; i <= MESSAGEAREA_MAX_MESSAGES; i++){
        setMessageAtLine(newMessagearea, NULL, i);
    }

    // print messagearea
    printCompleteMessagearea(newMessagearea);

    // return pointer
    return newMessagearea;
}


//*********************************************************
//* free module
void freeMessageareaAndContent(messagearea_t* theMessagearea)
{
    if (theMessagearea != NULL){
        // free messages
        int i;
        for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++) {
            freeMessageAndContent(theMessagearea -> messageLine[i]);
        }
    }

    // free self
    freeMessagearea(theMessagearea);
}


//*********************************************************
//* module management
void moveMessageareaToIndex(messagearea_t* theMessagearea, int lineNumber)
{
    // remove old messagearea
    removeMessageareaFromDisplay(theMessagearea);

    // set new base index
    setMessageareaBaseIndex(theMessagearea, lineNumber);

    // draw new messagearea
    printCompleteMessagearea(theMessagearea);
}


//*********************************************************
//* module content management
void clearMessagelineInMessagearea(messagearea_t* theMessagearea, int lineNumber)
{
    // free the old message
    freeMessageAndContent(theMessagearea -> messageLine[lineNumber - 1]);

    // set default value
    setMessageAtLine(theMessagearea, NULL, lineNumber);

    // remove from display
    eraseMessageareaLineInDisplay(theMessagearea, lineNumber);
}

void setMessageAtLineWithString(messagearea_t* theMessagearea,int lineNumber, char* theString)
{
    // free old message
    clearMessagelineInMessagearea(theMessagearea, lineNumber);

    // set new message
    if (theString != NULL){
        setMessageAtLine(theMessagearea, initializeMessageWithString(theString), lineNumber);
    }

    // write to display
    printMessagelineToDisplay(theMessagearea, lineNumber);
}

void setAllMessagesWithStrings(messagearea_t* theMessagearea, char* string1, char* string2, char* string3)
{
    char* ar[3];
    ar[0] = string1;
    ar[1] = string2;
    ar[2] = string3;

    int i;
    for (i = 1; i <= MESSAGEAREA_MAX_MESSAGES; i++){
        setMessageAtLineWithString(theMessagearea, i, ar[i -1]);
    }
}


//*********************************************************
//* output management


//*********************************************************
//* display management
void printCompleteMessagearea(messagearea_t* theMessagearea)
{
    // print the boarder
    printMessageareaBorder(theMessagearea);

    // print contents
    int i;
    for (i = 1; i <= MESSAGEAREA_MAX_MESSAGES; i++){
        printMessagelineToDisplay(theMessagearea, i);
    }
}

void updateWormStatus(messagearea_t* theMessagearea, board_t* theBoard, worm_t* theWorm)
{
    pos_t headpos;
    
    headpos = getWormHeadpos(theWorm);

    char* statusMessage[MESSAGEAREA_MAX_MESSAGES];
    char* buff[MESSAGEAREA_MAX_MESSAGES];

    // define status messages
    statusMessage[0] = "Anzahl verbleibender Futterbrocken: %2d";
    statusMessage[1] = "Der Wurm ist an Position: x= %3d y=%3d";
    statusMessage[2] = "Laenge des Wurms: %3d";


    // reserve mem for buffer
    int i;
    for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++) {
        buff[i] = malloc(strlen(statusMessage[i] + 1) * sizeof(char));
    }
    

    // build string to display
    sprintf(buff[0], statusMessage[0], getNumberOfFoodItems(theBoard));
    sprintf(buff[1], statusMessage[1], headpos.x, headpos.y);
    sprintf(buff[2], statusMessage[2], getWormLength(theWorm));

    
    // update messagearea with final strings
    setAllMessagesWithStrings(theMessagearea, buff[0], buff[1], buff[2]);


    // free buffer
    for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++) {
        free(buff[i]);
    }
}

int printDialog(messagearea_t* theMessagearea, char* prompt1, char* prompt2)
{
    // check if first prompt is present, otherwise return error
    if (prompt1 == NULL) {
        return RES_FAILED;
    }

    // clean Messagearea
    int i;
    for (i=1; i<=MESSAGEAREA_MAX_MESSAGES;i++){
        eraseMessageareaLineInDisplay(theMessagearea, i);
    }

    // assign messagestrings
    setAllMessagesWithStrings(theMessagearea, prompt1, prompt2, "Bitte Taste druecken.");

    // refresh the display
    refreshDisplay();

    // wait for userinput
    nodelay(stdscr, FALSE);
    int ch = getch();   // wait for user to press a key
    nodelay(stdscr, TRUE);

    // clear messagearea
    freeMessageareaAndContent(theMessagearea);

    // refresh display
    refreshDisplay();

    return ch;
}


//*********************************************************
//* display interaction
void fillMessagearealineWithSymbol(messagearea_t* theMessagearea, int lineNumber, char symbol)
{
    fillPartialDisplaylineWithSymbol(theMessagearea -> baseIndex + lineNumber, symbol, 1 + MESSAGEAREA_BLANKS_RESERVED_LEFT, BOARD_MIN_WIDTH - 2 - MESSAGEAREA_BLANKS_RESERVED_RIGHT);
}

void eraseMessageareaLineInDisplay(messagearea_t* theMessagearea, int lineNumber)
{
    fillMessagearealineWithSymbol(theMessagearea, lineNumber, SYMBOL_FREE_CELL);
}

void printMessagelineToDisplay(messagearea_t* theMessagearea, int lineNumber)
{
    if (theMessagearea -> messageLine[lineNumber - 1] != NULL){
        // print message
        printStringToMessagearea(theMessagearea, lineNumber, theMessagearea -> messageLine[lineNumber - 1] -> msgString);
    } else {
        // erase line in Display
        eraseMessageareaLineInDisplay(theMessagearea, lineNumber);
    }
}

void printStringToMessagearea(messagearea_t* theMessagearea, int lineNumber, char* theString){
    // set line to write to
    int displaylineIndex = theMessagearea -> baseIndex + lineNumber;

    // variable blanks on left side
    fillPartialDisplaylineWithSymbol(displaylineIndex, SYMBOL_FREE_CELL, 1, 1 + MESSAGEAREA_BLANKS_RESERVED_LEFT);

    // calc the max stringlength
    int maxIndex = BOARD_MIN_WIDTH - 1 - MESSAGEAREA_BLANKS_RESERVED_RIGHT;

    // write string to display
    int curIndex;
    int curPos = 1 + MESSAGEAREA_BLANKS_RESERVED_LEFT;
    for (curIndex = 0; curPos <= maxIndex && theString[curIndex] != '\0'; curPos++, curIndex++){
        placeItemInDisplay(curPos, displaylineIndex, theString[curIndex], COLP_DEFAULT);
    }

    // fill remaining space with blanks
    fillPartialDisplaylineWithSymbol(displaylineIndex, SYMBOL_FREE_CELL, curPos, maxIndex);
}

void printMessageareaBorder(messagearea_t* theMessagearea)
{
    int lineIndex = theMessagearea -> baseIndex;
    int i;

    for (i = 0; i < MESSAGEAREA_MIN_HEIGHT; i++) {
        if ( i == 0 || i == MESSAGEAREA_MIN_HEIGHT - 1) {
            fillDisplaylineWithSymbol(lineIndex + i, SYMBOL_MESSAGEAREA_BORDER);
        } else {
            placeItemInDisplay(0, lineIndex + i, SYMBOL_MESSAGEAREA_BORDER, COLP_MESSAGEAREA_BORDER);
            placeItemInDisplay(BOARD_MIN_WIDTH - 1,lineIndex + i, SYMBOL_MESSAGEAREA_BORDER, COLP_MESSAGEAREA_BORDER);
        }
    }
}

void removeMessageareaFromDisplay(messagearea_t* theMessagearea)
{
    int i;

    for (i = 0; i < MESSAGEAREA_MIN_HEIGHT; i++){
        fillPartialDisplaylineWithSymbol(theMessagearea -> baseIndex + i, SYMBOL_FREE_CELL, 0, BOARD_MIN_WIDTH - 1);
    }
}
