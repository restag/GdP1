/*
Diese Übung beinhaltet das trimmen von Strings und das Erstellen von Funktionen
*/


#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

		if (!(isblank(t[i]) || t[i] == '\n')) {

            t[k] = t[i];
            k++;

		}
	}
    
    t[k] = '\0';

    return t;
}
