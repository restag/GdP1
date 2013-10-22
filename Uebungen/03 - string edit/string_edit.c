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

void crop(char *string) {

	int i = stringLaenge(string);

	if (string[i-1] == '\n') {

		string[i-1] = '\0';

	}
}

int main()
{
	int c; // for input flush
	int stringLength;
	char inputString[CACHESIZE];

	puts(DIVLINE);

	while (strcmp(inputString, ENDSTRING) != 0) {

		// nach input fragen
		printf("Bitte einen String eingeben: ");


		// Input lesen
		fgets(inputString, CACHESIZE, stdin);


		// crop input string
		crop(inputString);


		// Länge lesen
		stringLength = stringLaenge(inputString);


		// input Cache löschen
		while ((c = getchar()) != '\n' &&  c != EOF);


		// '\n' von String löschen
		crop(inputString);


		//  Ergebnis ausgeben
		printf("Die Länge des Strings %s beträgt %d Zeichen.\n", inputString, stringLength);

		puts(DIVLINESMALL);

	}

	printf("Programm wurde beendet\n");

	return 0;
}
