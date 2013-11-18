/*
Diese Übung beinhaltet das trimmen von Strings und das Erstellen von Funktionen

Lösung mit globaler Variable
*/


#include <ctype.h>
#include <stdio.h>

#define RESULT_MAX 256


char result[RESULT_MAX];

char* trim(char* t);

int main(void) {
    char test[] = "Das hier \n ist der \n Teststring";

    printf("%s\n", trim(test));
    return 0;
}

char* trim(char* t){

	int i;
    int k = 0;

	for (i = 0; t[i] != '\0'; i++) {
        if (k >= RESULT_MAX -1) break;
		if (!(isblank(t[i]) || t[i] == '\n')) {

            result[k] = t[i];
            k++;

		}
	}
    
    result[k] = '\0';

    return result;
}
