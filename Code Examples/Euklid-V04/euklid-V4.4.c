// Alternative Implementierung der Funktion readInteger (Variante zu euklid-V4.3.c)
// Hier wird der Name der Integer-Variable uebergeben und daraus der Prompt generiert.
// Der Prompt ist optional
// Die finale Fehlermeldung erfolgt in der Funktion readInteger und nicht beim Aufrufer, hier main
//

#include <stdio.h>
#define OK 0
#define ERROR 1

int ggT(int a, int b) {
    while (a != b) {
        if (a < b)
            b = b - a;
        else
            a = a - b;
    }
    return a;
}

int readInteger(char varname[], int* addrInt) {
    int versuche = 2;
    int erfolg = 0;

    while(versuche > 0 && !erfolg) {
        if (varname != NULL && varname[0] != '\0') {
            printf("%s=",varname);
            fflush(stdout);
        }

        if(scanf("%d", addrInt) != 1) {
            versuche--;
            printf("Du musst eine Zahl eingeben! Noch %d Versuch(e)\n",versuche);
        } else {
            erfolg=1;
        }
        while(getchar() != '\n');
    }

    if (erfolg) {
        return OK;    
    } else {
        printf("Fehler bei der Eingabe der Zahl %s\n",varname);
        return ERROR;
    }
}

int main (void) {
    int i1;
    int i2;

    /* Lies zwei ganze Zahlen in i1 und i2 ein */

    if ( readInteger("i1", &i1) != OK) {
        return ERROR;
    }


    if ( readInteger("i2", &i2) != OK) {
        return ERROR;
    }


    printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
            i1,i2,ggT(i1,i2));
    return OK;
}
