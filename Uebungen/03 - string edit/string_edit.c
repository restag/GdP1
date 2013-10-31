/*
Übung 02 - string edit

Inhalt dieser Übung ist es eine Schleife zu programmieren, im Rumpf nach neuen Strings
zu fragen und die Ländie des Strings auszugeben.

Implementierung über "int stringLaenge(char string[])".

Note: 	strlen() nicht verwenden
Note:	Beenden der Schleife mit String "Ende"
Note:	nach jeder Zeile Eingabepuffer leeren

*/

#define 	DIVLINE "==========================="
#define		DIVLINESMALL "======="
#define		CACHESIZE 20
#define		ENDSTRING "Ende"

#include <stdio.h>
#include <string.h>

int stringLaenge(char string[])
{
	int i = 0;

	while (string[i] != '\0') {

		i++;

	}

	return i;
}

int main()
{
	char c;
	int i;
	char inputString[CACHESIZE];

	puts(DIVLINE);

	while (strcmp(inputString, ENDSTRING) != 0) {

		i = 0;

		// nach input fragen
		printf("Bitte einen String eingeben: ");


		// Input lesen
		while ((c = getchar()) != '\n' && c != EOF) {

			if (i < CACHESIZE) {
				// Chars einlesen & speichern
				inputString[i] = c;
			}

			i++;

		}

		// Stringterminierung
		if (i < CACHESIZE) {
			inputString[i] = '\0';
		} else {
			inputString[CACHESIZE] = '\0';
		}

		//  Ergebnis ausgeben
		printf("Die Länge des Strings \"%s\" beträgt %d Zeichen.\n", inputString, stringLaenge(inputString));

		puts(DIVLINESMALL);
	}

	printf("Programm wurde beendet\n");

	return 0;
}
