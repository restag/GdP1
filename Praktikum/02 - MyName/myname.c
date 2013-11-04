/* Übung 02 - MyName


Es werden zwei Zeilen Code ausgegeben
*/

#include <stdio.h>


int main(){

	char name[] = "Benjamin Ewert";
	int day = 15;
	int month = 8;
	int year = 1985;

	printf("Mein Name ist %s\n", name);
	printf("Mein Geburtsdatum ist der %02d.%02d.%04d.\n", day, month, year);

	return 0;
}
