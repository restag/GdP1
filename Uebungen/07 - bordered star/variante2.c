/* This is an exercise for working with 2dim. arrays 
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// include framework headers below here

// include headers below here
#include "variante2.h"

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
    baueStern(dasBild, ZEILEN, SPALTEN, 1, 1);

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
    machStrahl(einBild, rows, cols, z0, s0, -1, 0);
    machStrahl(einBild, rows, cols, z0, s0, -1, 1);
    machStrahl(einBild, rows, cols, z0, s0, 0, 1);
    machStrahl(einBild, rows, cols, z0, s0, 1, 1);
    machStrahl(einBild, rows, cols, z0, s0, 1, 0);
    machStrahl(einBild, rows, cols, z0, s0, 1, -1);
    machStrahl(einBild, rows, cols, z0, s0, 0, -1);
    machStrahl(einBild, rows, cols, z0, s0, -1, -1);
}

void machStrahl(char einBild[][SPALTEN], int rows, int cols, int z0, int s0, int xStep, int yStep)
{
    int row = z0;
    int col = s0;
    char baseChar = 'a';
    char* tmpChar = &baseChar;
    int tmpInt = *tmpChar;

    while (row > 0 && col > 0 && row < rows-1 && col < cols-1){
        einBild[row][col] = tmpInt;
        tmpInt += 1;
        row += xStep;
        col += yStep;
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
