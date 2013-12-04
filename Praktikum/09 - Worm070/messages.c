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
 * Displaying messages and dialogs
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <curses.h>

// put custom header includes below here
#include "messages.h"
#include "prep.h"
#include "worm_model.h"
#include "board_model.h"


//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* message box
//Clear an entire line on the display
void clearLineInMessageArea(int row) {
    int i;

    move(row,0);
    for (i = 1; i <= COLS; i++) {
        addch(' ');
    }
}

// Display status about the game in the message area
void showStatus(board_t* aboard, worm_t* aworm) {
    int pos_line1 = LINES - ROWS_RESERVED + 1;
    int pos_line2 = LINES - ROWS_RESERVED + 2;
    int pos_line3 = LINES - ROWS_RESERVED + 3;

    pos_t headpos = getWormHeadPos(aworm);
    mvprintw(pos_line1, 1, "Anzahl verbleibender Futterbrocken: %2d", getNumberOfFoodItems(aboard));
    mvprintw(pos_line2, 1, "Wurm ist an Position: y=%3d x=%3d", headpos.y, headpos.x);
    mvprintw(pos_line3, 1, "Länge des Wurms: %3d", getWormLength(aworm));
}

// Display a dialog in the message area and wait for confirmation
// String prompt1 is displayed in the second line of the message area
// String prompt2 is displayed in the  third line of the message area
int showDialog(char* prompt1, char* prompt2) {
    int pos_line1 = LINES -ROWS_RESERVED + 1;
    int pos_line2 = LINES -ROWS_RESERVED + 2;
    int pos_line3 = LINES -ROWS_RESERVED + 3;

    int ch;

    if (prompt1 == NULL) {
        return RES_FAILED;
    } 

    // Delete lines in the message area
    clearLineInMessageArea(pos_line1);
    clearLineInMessageArea(pos_line2);
    clearLineInMessageArea(pos_line3);

    // Display message
    mvprintw(pos_line2 , 1, "%s", prompt1);
    if (prompt2 != NULL) {
        mvprintw(pos_line3 , 1, "%s", prompt2);
    }
    refresh();

    nodelay(stdscr, FALSE);
    ch = getch();   // Wait for user to press an arbitrary key
    nodelay(stdscr, TRUE);

    // Delete lines in the message area
    clearLineInMessageArea(pos_line1);
    clearLineInMessageArea(pos_line2);
    clearLineInMessageArea(pos_line3);

    // Display changes
    refresh();

    // Return code of key pressed
    return ch; 
}
