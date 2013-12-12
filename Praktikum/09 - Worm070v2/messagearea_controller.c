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


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// put custom header includes below here
#include "messagearea_controller.h"
#include "message_controller.h"
#include "game_controller.h"

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
        newMessagearea -> messageLine[i] = initializeMessage();
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
//* area management
void moveMessageareaToIndex(messagearea_t* theMessagearea, int lineIndex)
{
    setMessageareaBaseIndex(theMessagearea, lineIndex);
}


//*********************************************************
//* content management
void clearLineInMessagearea(messagearea_t* theMessagearea, int lineNumber)
{
    // free messageline content
    freeMessageAndContent(theMessagearea -> messageLine[lineNumber - 1]);

    // set blank messageline
    setMessageAtLine(theMessagearea, NULL, lineNumber);

    // erase messageline in display
    eraseMessagelineInDisplay(theMessagearea, lineNumber);
}

void setAllMessagesWithStrings(messagearea_t* theMessagearea, char* string1, char* string2, char* string3)
{
    char* ar[MESSAGEAREA_MAX_MESSAGES];

    // assign prompts
    ar[0] = string1;
    ar[1] = string2;
    ar[2] = string3;


    // set messages
    int i;

    for (i = 1; i <= MESSAGEAREA_MAX_MESSAGES; i++){
        clearLineInMessagearea(theMessagearea, i);
        setMessageAtLine(theMessagearea, initializeMessageWithString(ar[i - 1]), i);
    }
}


//*********************************************************
//* prepping for output
void updateWormStatus(messagearea_t* theMessagearea, board_t* theBoard, worm_t* theWorm)
{
    
    pos_t headpos = getWormHeadpos(theWorm);
    char* statusMessage[MESSAGEAREA_MAX_MESSAGES];
    char* buff[MESSAGEAREA_MAX_MESSAGES];

    // define status messages
    statusMessage[0] = "Anzahl verbleibender Futterbrocken: %2d";
    statusMessage[1] = "Der Wurm ist an Position: x= %3d y=%3d";
    statusMessage[2] = "Länge des Wurms: %3d";


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


//*********************************************************
//* display management
void printMessagearea(messagearea_t* theMessagearea)
{
    int i;

    // print lines
    for (i = 0; i < MESSAGEAREA_MAX_MESSAGES; i++){
        if (theMessagearea -> messageLine[i] != NULL) {
            // messageline is set
            printMessageline(theMessagearea, i + 1);
        } else {
            // messageline is blank, so make sure the displayline is empty
            eraseMessagelineInDisplay(theMessagearea, i + 1);
        }
    }
}

int printDialog(messagearea_t* theMessagearea, char* prompt1, char* prompt2, char* prompt3)
{
    // check if first prompt is present, otherwise return error
    if (prompt1 == NULL) {
        return RES_FAILED;
    }

    // assign messagestrings
    setAllMessagesWithStrings(theMessagearea, prompt1, prompt2, prompt3);
    printMessagearea(theMessagearea);

    // refresh the display
    refresh();

    // wait for userinput
    nodelay(stdscr, FALSE);
    int ch = getch();   // wait for user to press a key
    nodelay(stdscr, TRUE);

    // clear messagearea
    setAllMessagesWithStrings(theMessagearea, NULL, NULL, NULL);
    printMessagearea(theMessagearea);

    // refresh diisplay
    refresh();

    return ch;
}


//*********************************************************
//* display interaction
void eraseMessagelineInDisplay(messagearea_t* theMessagearea, int lineNumber)
{
    int i;

    // move to line in curses display buffer
    move(theMessagearea -> baseIndex + lineNumber, 0);

    // print to curses display buffer
    for (i = 1; i <= COLS; i++) {
        addch(' ');
    }
}

void printMessageline(messagearea_t* theMessagearea, int lineNumber)
{
    mvaddstr(theMessagearea -> baseIndex + lineNumber, 1, theMessagearea -> messageLine[lineNumber] -> msgString);
}
