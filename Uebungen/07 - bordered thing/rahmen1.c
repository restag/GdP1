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
    // draw border

    drucke();

    return 0;
}


// draw a border
void baueRahmen() {
    int i,j;

    for (i=0;i<ZEILEN;i++){
        for (j=0;j<SPALTEN;j++) {
            bild[i][j] = ' ';
        }
    }

    for (j=0; j<SPALTEN; j++) {
        bild[0][j] = '*';
        bild[ZEILEN-1][j] = '*';
    }

    for (i=0; i<ZEILEN; i++) {
        bild[i][0] = '*';
        bild[i][ZEILEN-1] = '*';
    }

}



// print all
void drucke() {
    int i,j;

    for (i=0; i<ZEILEN; i++) {
        for (j=0;i<SPALTEN; j++) {
            // print char
            printf("%c", bild[i][j]);
        }

        // linebreak
        printf("\n");
    }
}
