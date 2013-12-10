/* put a description in here 
 *
 */

#ifndef _WORM_CONTROLLER_H
#define _WORM_CONTROLLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "worm_model.h"
#include "board_model.h"

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


//*********************************************************
//* struct type definitions
//*********************************************************
// put struct typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here
worm_t* createDefaultWorm();
worm_t* createUserWorm(board_t* aboard);
void setWormHeading(worm_t* aworm, wormheading_t dir);
#endif  // #define _WORM_CONTROLLER_H:w

