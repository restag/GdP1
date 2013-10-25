// Verbesserung der Version euklid-V4.2
// Einlesen einer Interzahl durch Funktion readInteger

#include <stdio.h>
#define OK 0
#define ERROR 1

int ggT(int a, int b) {
    // Fix fuer negative Zahlen
    if (a < 0) { a = -a; }
    if (b < 0) { b = -b; }

    while (a != b) {
        if (a < b)
            b = b - a;
        else
            a = a - b;
    }
    return a;
}

int readInteger(char* prompt, int* n) {

    int erfolg = 0;
    int zaehler = 2;    // Anzahl der Versuche

    while (!erfolg && zaehler > 0) {
        printf("%s",prompt);
        fflush(stdout);

        if(scanf("%d", n) != 1) {
            zaehler--;
            printf("Sie muessen hier eine Zahl eingeben!!!\n");
        } else {
            erfolg = 1;
        }
        while(getchar() != '\n');
    }

    // Stelle fest, wieso wir Schleife verlassen haben
    if (!erfolg) {
        return ERROR;
    } else {
        return OK;
    }
}


int main (void) {
    int i1;
    int i2;

    /* Lies zwei ganze Zahlen in i1 und i2 ein */

    if(readInteger("i1=", &i1) != OK ) {
        printf("Fehler bei der Eingabe der Zahl i1\n");
        return ERROR;
    }

    if(readInteger("i2=", &i2) != OK ) {
        printf("Fehler bei der Eingabe der Zahl i2\n");
        return ERROR;
    }


    printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
        i1,i2,ggT(i1,i2));
    return OK;
}
