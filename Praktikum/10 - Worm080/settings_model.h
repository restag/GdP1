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


#ifndef _SETTINGS_MODEL_H
#define _SETTINGS_MODEL_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here
#include <stdbool.h>

// put custom header includes below here


//*********************************************************
//* defines
//*********************************************************
// put defines below here
// board_related


// worm_related
#define DEFAULT_NAP_TIME 100
#define DEFAULT_NUMBER_OF_WORMS 1
#define DEFAULT_START_MODE false

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
struct Settings {
    int nap_time;               // Time in milliseconds to sleep at the end of level loop
    bool start_single_step;     // start game in single step mode
    int number_of_worms;        // the number of worms in the game
};

//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here
typedef struct Settings settings_t;

//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here

//* model allocation
settings_t* allocSettings(void);

//* free model
void freeSettingsSet(settings_t* settingsSet);

//* model setters
void setNaptime(settings_t* settingsSet, int napTime);
void setStartInSingleStepFlag(settings_t* settingsSet, bool flag);
void setNumberOfWorms(settings_t* settingsSet, int numberOfWorms);

//* getters
int getNaptime(settings_t* settingsSet);
bool getStartInSingleStepFlag(settings_t* settingsSet);
int getNumberOfWorms(settings_t* settingsSet);

#endif  // #define _SETTINGS_MODEL_H
