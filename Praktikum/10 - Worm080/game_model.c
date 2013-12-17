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
 * The boardmodel contains the data needed for board creation and handling
 *
 * Tasks:
 *      * memory allocation & freeing
 *      * value modification
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here
#include <stdlib.h>

// put custom header includes below here
#include "game_model.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* model allocation
game_t* allocGame(void)
{
    game_t* newGame = malloc(sizeof(game_t));

    return newGame;
}


//*********************************************************
//* free model
void freeGame(game_t* theGame)
{
    free(theGame);
}


//*********************************************************
//* setters
void setGameboard(game_t* theGame, board_t* theBoard)
{
    theGame -> gameboard = theBoard;
}

void setMessageareaForGame(game_t* theGame, messagearea_t* theMessagearea)
{
    theGame -> messagearea = theMessagearea;
}

void setSettingssetForGame(game_t* theGame, settings_t* theSet)
{
    theGame -> settingsset = theSet;
}

void setWormAtIndex(game_t* theGame, worm_t* theWorm, int index)
{
    theGame -> worms[index] = theWorm;
}

//*********************************************************
//* getters
board_t* getGameboard(game_t* theGame)
{
    return theGame -> gameboard;
}

messagearea_t* getMessageareaFromGame(game_t* theGame)
{
    return theGame -> messagearea;
}

settings_t* getSettingssetFromGame(game_t* theGame)
{
    return theGame -> settingsset;
}

worm_t* getWormAtIndex(game_t* theGame, int index)
{
    return theGame -> worms[index];
}
