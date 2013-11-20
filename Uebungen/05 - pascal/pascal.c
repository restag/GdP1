/* Diese Übung erstellt ein pascalsches Dreieck
 *
 * Die auszugebende Tiefe wird als Parameter übergeben
 *
 * Diese Lösungsvariante benutzt einen iterativen Ansatz
 */

#include <stdio.h>
#include <stdlib.h> // for atoi

int pascal(int z, int s);

int main (int argc, char* argv[]){

    // Auslesen der Argumente
    if (argc > 2) {
        puts("Usage: pascal <depth>.");
        puts("You are only allowed to enter a single number!");
        return 1;
    }

    int depth = atoi(argv[1]);

    // Erstellen des Arrays
    int triangle[depth][depth];


    // Füllen des Dreiecks
    int s;
    int z;

    for (z = 0; z < depth; z++) {

        for (s = 0; s < depth; s++) {
            
            if (s == 0 || z == 0) {
                triangle[z][s] = 1;
            } else {
                triangle[z][s] = pascal(triangle[z][s-1], triangle[z-1][s]);
            }

            // Ausgabe des Wertes
            printf(" %3d", triangle[z][s]);
        }

        // Zeilenumbruch für Ausgabe
        printf("\n");

    }


    return 0;
}

int pascal(int z, int s) {
    return z + s;
}
