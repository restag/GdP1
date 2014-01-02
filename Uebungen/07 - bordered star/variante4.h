/* This is an exercise for working with 2 dim arrays
 *
 * This Version uses a recusrive approach to draw the star and an
 * APA approach to store the data
 *
 */

#ifndef _VARIANTE4_H
#define _VARIANTE4_H
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
char** initTable(int rows, int cols);
void baueStern(char** einBild, int rows, int cols, int z0, int s0);
void machStrahl(char** einBild, int rows, int cols,  int z0, int s0, int xStep, int yStep, int lastChar);
void drucke(char** einBild, int rows);

#endif  // #define _VARIANTE4_H
