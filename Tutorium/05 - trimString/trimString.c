/*
Diese Übung beinhaltet das trimmen von Strings und das Erstellen von Funktionen
*/


#include <stdio.h>
#include <strings.h>

char* trim(char[] t){

	int i;

	for (i = 0; t[i] != '\0'; i++) {

		if (isblank(t[i]) || t[i] == '\n') {


		}		

	}

	return t;
}

int main (void){
	char mySting [] = "Dies ist der verdammte String der getrimmt werden soll.";

	
	printf("%s", trim(myString));
	return 0;
}
