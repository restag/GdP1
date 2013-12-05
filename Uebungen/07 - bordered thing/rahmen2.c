/* This is an exercise for working with 2dim. arrays 
 *
 */

//*********************************************************
//* header includes
//*********************************************************
// include framework headers below here

// include headers below here
#include "rahmen1.h"

//global var

//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main()
{
    char dasBild[ZEILEN][SPALTEN];
    
    // build border
    baueRahmen(dasBild, ZEILEN, SPALTEN);

    // draw border
    drucke(dasBild, ZEILEN, SPALTEN);

    return 0;
}


// draw a border
void baueRahmen(char einBild[][SPALTEN], int rows, int cols) {
    int i,j;

    // fill array with blanks
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++) {
            einBild[i][j] = ' ';
        }
    }

    // fill first and last row with *
    for (j=0; j<rows; j++) {
        einBild[0][j] = '*';
        einBild[cols-1][j] = '*';
    }

    // fill first and last col with *
    for (i=0; i<rows; i++) {
        einBild[i][0] = '*';
        einBild[i][cols-1] = '*';
    }

}



// print all
void drucke(char einBild[][SPALTEN], int rows, int cols) {
    int i,j;

    for (i=0; i<rows; i++) {

        // print char
        for (j=0;j<cols; j++) {
            printf("%c", einBild[i][j]);
        }

        // linebreak
        printf("\n");
    }
}
