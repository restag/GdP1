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
	char inputString[CACHESIZE];

	puts(DIVLINE);
	printf("Bitte einen String eingeben: ");

	while (1) {

		scanf("%s", inputString);

		if (strcmp(inputString, ENDSTRING) == 0) {

			break;

		}

		printf("Die Länge des Strings %s beträgt %d Zeichen.\n", inputString, stringLaenge(inputString));

		// input Cache leeren
		fflush(stdin);

		puts(DIVLINESMALL);
		printf("Bitte nächsten String eingeben: ");

	}

	puts(DIVLINE);
	printf("Programm wurde beendet\n");

	return 0;
}
