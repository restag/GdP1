/*
Uebung 01 - Interval Output

Dieses Programm fragt nach zwei Zahlen (Integer) als Intervalgrenzen.
Danach werden alle ungerade Integer innerhalb dieses Intervals ausgegeben.

Note: 	Intervalgrenzen werden mit einbezogen
Note: 	Intervalgrenzen werden automatisch geordnet
Note:	Fehlermeldung falls Interval zu klein
Note:	Fehlermeldung bei ungültigem Input
*/

#include <stdio.h>

// Definiere Trennlinie

#define DIVLINE "============================"

int main()
{
	int inputOne;
	int inputTwo;
	int intervalStart;
	int intervalStop;

	// declare counter
	int i;

	// Frage nach erster Zahl
	printf("Bitte geben Sie die Intervalgrenze 1 ein:\n");
	scanf("%d", &inputOne);

	// Frage nach zweiter Zahl
	printf("Bitte geben Sie die zweite Intervalgenze ein:\n");
	scanf("%d", &inputTwo);

	// sortiere Intervalgrenzen
	if (inputOne > inputTwo) {

		intervalStart = inputTwo;
		intervalStop = inputOne;

	} else if (inputTwo > inputOne) {

		intervalStart = inputOne;
		intervalStop = inputTwo;

	} else if (inputOne == inputTwo) {

		printf("Fehler: Intervalstart und Intervalende darf nicht identisch sein!\n");
		return 0;

	}

	// Überprüfe mindestgröße des Intervals
	if ((intervalStop-intervalStart)<2) {

		printf("Fehler: Interval zu klein!\n");
		return 0;

	}

	// Gebe Intervalgrenzen aus
	puts(DIVLINE);
	printf("Intervalstart: %d\n", intervalStart);
	printf("Intervalende: %d\n", intervalStop);
	puts(DIVLINE);

	// Gebe Elemente aus
	printf("Das Interval enthält folgende Element:\n");

	for (i=intervalStart; i<=intervalStop; i++) {

		if ((i%2) == 1) {

			printf("%d\n", i);

		}

	}

	puts(DIVLINE);
	printf("Program fertig\n");


	return 0;
}
