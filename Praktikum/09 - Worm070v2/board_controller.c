/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
board_t* createGameBoard()
{
    board_t* theBoard;

    theBoard = allocBlankBoard();
    initializeDefaultBoard(theBoard);

    // fill with food
    // here

    return theBoard;
}

//*********************************************************
//* setters

//*********************************************************
//* getters

