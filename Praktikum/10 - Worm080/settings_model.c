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
#include "settings_model.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* model allocation
settings_t* allocSettings(void)
{
    settings_t* newSettingsSet = malloc(sizeof(settings_t));

    return newSettingsSet;
}

//*********************************************************
//* free model
void freeSettingsSet(settings_t* settingsSet)
{
    free(settingsSet);
}

//*********************************************************
//* setters
void setNaptime(settings_t* settingsSet, int napTime)
{
    settingsSet -> nap_time = napTime;
}

void setStartInSingleStepFlag(settings_t* settingsSet, bool flag)
{
    settingsSet -> start_single_step = flag;
}

void setNumberOfWorms(settings_t* settingsSet, int numberOfWorms)
{
    settingsSet -> number_of_worms = numberOfWorms;
}

//*********************************************************
//* getters
int getNaptime(settings_t* settingsSet)
{
    return settingsSet -> nap_time;
}

bool getStartInSingleStepFlag(settings_t* settingsSet)
{
    return settingsSet -> start_single_step;
}

int getNumberOfWorms(settings_t* settingsSet)
{
    return settingsSet -> number_of_worms;
}
