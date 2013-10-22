/*
Übung 03 Stringpuffer

Programm ließt String ein und gibt diesen aus.
Es werden alle Leerzeichen entfernt.

*/

#include <stdio.h>
#include <string.h>

#define PUFFERGROESSE 20
#define	ERROR 1
#define STRINGTOSTRIP ' '

int main()
{
	char outputString[PUFFERGROESSE];
	int i = 0;
	int n = 0;

// Vorgabe Start
	char stringPuffer[PUFFERGROESSE];
	printf("Bitte String eingeben:"); fflush(stdout);

	if (fgets(stringPuffer, PUFFERGROESSE, stdin) == NULL) {

		printf("Fehler beim einlesen\n");
		//return ERROR;

	}
// Vorgabe Ende

	// Schleife zum Durchlaufen des Inputstrings
	while (i <= strlen(stringPuffer)) {

		// Vergleich des aktuellen Zeichens im Inputstring mit zu entfernendem String
		if (stringPuffer[i] != STRINGTOSTRIP) {

			outputString[n] = stringPuffer[i];
			n++;

		}

		i++;
	}


	// Stringausgabe
	printf("Der eingegebene String lautet: %s\n", outputString);

	return 0;
}
