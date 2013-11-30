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
char bild[ZEILEN][SPALTEN];

//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main()
{
    // build border
    baueRahmen();

    // draw border
    drucke();

    return 0;
}


// draw a border
void baueRahmen() {
    int i,j;

    // fill array with blanks
    for (i=0;i<ZEILEN;i++){
        for (j=0;j<SPALTEN;j++) {
            bild[i][j] = ' ';
        }
    }

    // fill first and last row with *
    for (j=0; j<SPALTEN; j++) {
        bild[0][j] = '*';
        bild[ZEILEN-1][j] = '*';
    }

    // fill first and last col with *
    for (i=0; i<ZEILEN; i++) {
        bild[i][0] = '*';
        bild[i][ZEILEN-1] = '*';
    }

}



// print all
void drucke() {
    int i,j;

    for (i=0; i<ZEILEN; i++) {

        // print char
        for (j=0;j<SPALTEN; j++) {
            printf("%c", bild[i][j]);
        }

        // linebreak
        printf("\n");
    }
}
