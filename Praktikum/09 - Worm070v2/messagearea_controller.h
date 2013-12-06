/* put a description in here 
 *
 */

#ifndef _MESSAGEAREA_CONTROLER_H
#define _MESSAGEAREA_CONTROLER_H
//*********************************************************
//* header includes 
//*********************************************************
// put framework header includes below here

// put custom header includes below here
#include "messagearea_model.h"

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
// update the worm status
void updateWormStatus(messagearea_t* aMessageArea, worm_t* aworm);

// clear line of message area
void cleaLineInMessageArea (messagearea_t* aMessageArea, int lineNumber);

// show status in message area
void showStatus(message_area_t* aMessageArea, worm_t* aworm);


#endif  // #define _MESSAGEAREA_CONTROLER_H
