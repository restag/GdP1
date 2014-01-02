/* This is an exercise for working with 2dim. arrays 
 *
 * This version uses a recusrive approach to draw the star
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// include framework headers below here

// include headers below here
#include "variante3.h"

//global var

//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main(void)
{
    char dasBild[ZEILEN][SPALTEN];
    
    // build border
    baueRahmen(dasBild, ZEILEN, SPALTEN);

    // build star
    baueStern(dasBild, ZEILEN, SPALTEN, 7, 7);

    // draw border
    drucke(dasBild, ZEILEN, SPALTEN);

    return 0;
}


// draw a border
void baueRahmen(char einBild[][SPALTEN], int rows, int cols) {
    int row, col;

    // fill array with blanks & border
    for (row=0; row < rows; row++){
        for (col=0; col < cols; col++) {
            if (row == 0 || row == ZEILEN -1 || col == 0 || col == SPALTEN -1){
                einBild[row][col] = '*';
            } else {
                einBild[row][col] = ' ';
            }
        }
    }
}

// draw star
void baueStern(char einBild[][SPALTEN], int rows, int cols, int z0, int s0)
{
    char base = 'a';
    char* tmpInt = &base;
    int baseChar = *tmpInt;

    einBild[z0][s0] = base;

    machStrahl(einBild, rows, cols, z0, s0, -1, 0, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, -1, 1, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, 0, 1, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, 1, 1, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, 1, 0, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, 1, -1, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, 0, -1, baseChar);
    machStrahl(einBild, rows, cols, z0, s0, -1, -1, baseChar);
}

void machStrahl(char einBild[][SPALTEN], int rows, int cols, int z0, int s0, int xStep, int yStep, int lastChar)
{
    int row = z0 + xStep;
    int col = s0 + yStep;

    if (row > 0 && col > 0 && row < rows-1 && col < cols -1){
        int nextChar = lastChar +1;

        einBild[row][col] = nextChar;
        machStrahl(einBild, rows, cols, row, col, xStep, yStep, nextChar);
    }
}

// print all
void drucke(char einBild[][SPALTEN], int rows, int cols) {
    int row, col;

    for (row=0; row < rows; row++) {

        // print char
        for (col=0; col < cols; col++) {
            printf("%c", einBild[row][col]);
        }

        // linebreak
        printf("\n");
    }
}
