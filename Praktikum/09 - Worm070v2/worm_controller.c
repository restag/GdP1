/* put a description in here 
 *
 */


//*********************************************************
//* header includes
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_controller.h"

//*********************************************************
//* global vars
//*********************************************************


//*********************************************************
//* fuctions
//*********************************************************
// put function codes below here

//*********************************************************
//* program main
worm_t* createDefaultWorm()
{
    // allocate new memory
    worm_t* newWorm = allocBlankWorm();

    // init to default
    initializeDefaultWorm(newWorm);

    // return
    return newWorm;
}

worm_t* createUserWorm(board_t* theBoard)
{
    worm_t* userWorm = createDefaultWorm();

    // userworm details
    pos_t userStartPos;
    userStartPos.x = 0;
    userStartPos.y = getLastRowOnBoard(theBoard);

    // initialize Userdetails
    initializeWormWithValues(userWorm, userStartPos, COLP_USER_WORM);
    setWormHeading(userWorm, WORM_RIGHT);

    return userWorm;
}

void setWormHeading(worm_t* aworm, wormheading_t dir)
{
    pos_t nextStep;

    switch(dir) {
        case WORM_UP :// User wants up
            nextStep.x= 0;
            nextStep.y= -1;
            break;
        case WORM_DOWN :// User wants down
            nextStep.x = 0;
            nextStep.y = 1;
            break;
        case WORM_LEFT      :// User wants left
            nextStep.x = -1;
            nextStep.y = 0;
            break;
        case WORM_RIGHT      :// User wants right
            nextStep.x = 1;
            nextStep.y = 0;
            break;
    }

    setNextStep(aworm, nextStep);
}

//*********************************************************
//* getters

