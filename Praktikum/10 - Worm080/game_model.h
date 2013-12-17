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


#ifndef _GAME_MODEL_H
#define _GAME_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "board_model.h"
#include "messagearea_model.h"
#include "settings_model.h"
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
struct Game {
    board_t* gameboard;
    messagearea_t* messagearea;
    settings_t* settingsset;
    worm_t** worms;
};

//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct Game game_t;

//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

//* model allocation
game_t* allocGame(void);

//* free model
void freeGame(game_t* aGame);

//* model setters
void setGameboard(game_t* aGame, board_t* aBoard);
void setMessageareaForGame(game_t* aGame, messagearea_t* aMessagearea);
void setSettingssetForGame(game_t* aGame, settings_t* aSettingsset);
void setWormAtIndex(game_t* aGame, worm_t* aWorm, int index);

//* getters
board_t* getGameboard(game_t* aGame);
messagearea_t* getMessageareaFromGame(game_t* aGame);
settings_t* getSettingssetForGame(game_t* aGame);
worm_t* getWormAtIndex(game_t* aGame, int index);

#endif  // #define _<MODULE-NAME>_MODEL_H
