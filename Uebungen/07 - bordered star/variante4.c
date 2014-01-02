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
#include "variante4.h"

//global var

//*********************************************************
//* fuctions
//*********************************************************
// put function code below here
int main(void)
{
    int rows = ZEILEN;
    int cols = SPALTEN;

    // init basepicture
    char** dasBild = initTable(rows, cols);
    
    // build star
    baueStern(dasBild, rows, cols, 7, 7);

    // draw border
    drucke(dasBild, rows);

    return 0;
}

// build datatable
char** initTable(int rows, int cols)
{
    int row, col;

    char** newBild = malloc(rows * sizeof(char*));

    for (row = 0; row < rows; row++){
        newBild[row] = malloc((cols+1) * sizeof(char));

        for (col=0; col < cols; col++) {
            if (row == 0 || row == rows-1 || col == 0 || col == cols-1){
                newBild[row][col] = '*';
            } else {
                newBild[row][col] = ' ';
            }
        }

        newBild[row][cols] = '\0';
    }

    return newBild;
}

// draw star
void baueStern(char** einBild, int rows, int cols, int z0, int s0)
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

void machStrahl(char** einBild, int rows, int cols, int z0, int s0, int xStep, int yStep, int lastChar)
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
void drucke(char** einBild, int rows) {
    int row;

    for (row=0; row < rows; row++) {

        // print line
        printf("%s", einBild[row]);

        // linebreak
        printf("\n");
    }
}
