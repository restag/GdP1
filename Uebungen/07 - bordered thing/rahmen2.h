/* put a description in here 
 *
 */

#ifndef _RAHMEN1_H
#define _RAHMEN1_H
//*********************************************************
//* header includes 
//*********************************************************
// put header includes below here
#include <stdio.h>
#include <stdlib.h>

//*********************************************************
//* defines
//*********************************************************
// put defines below here
#define ZEILEN 15
#define SPALTEN 15

//*********************************************************
//* type definitions
//*********************************************************
// typedefs below here


//*********************************************************
//* function prototypes
//*********************************************************
// put prototypes below here
void baueRahmen(char einBild[][SPALTEN], int rows, int cols);
void baueStern(char einBild[][SPALTEN], int rows, int cols, int s0, int z0);
void machStrahl(char einBild[][SPALTEN], int rows, int cols, int s0, int z0, int xStep, int yStep);
void drucke(char einBild[][SPALTEN], int rows, int cols);

#endif  // #define _RAHMEN1_H