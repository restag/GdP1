/* A simple version of a debugging file
 *
 * Usage:
 * add the files debug.h and debug.c to your project and
 * include debug.h into your main headerfile
 *
 * Author:
 * Benjamin Ewert
 * (c) 2013
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// include framework headers below here
#include <stdio.h>
// include headers below here
#include "debug.h"


//*********************************************************
//* fuctions
//*********************************************************
// user input related
void waitForUserInput()
{
    int ch;

    // wait for the user input
    ch = getchar();

    ch = ch; // hide warning for unused var
    
    return;
}
