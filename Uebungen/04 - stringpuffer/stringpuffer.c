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
#define INTRO "Bitte String eingeben:"
#define OUTPUT "Der eingegebene Sting lautet: %s"
#define ERROROUT "Fehler beim einlesen"
#define MAXREACHED "Es wurde die Puffergröße überschritten, weitere Zeichen wurden entfernt"

int main()
{
	char outputString[PUFFERGROESSE];
	int i = 0;
	int n = 0;

// Vorgabe Start
	char stringPuffer[PUFFERGROESSE];
	puts(INTRO);

	if (fgets(stringPuffer, PUFFERGROESSE, stdin) == NULL) {

		puts(ERROROUT);
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
	printf(OUTPUT, outputString);

	return 0;
}
