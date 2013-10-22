/*
 * Vervollstaendigen Sie die printf Aufrufe
 * indem Sie die Variablen den richtigen printf(...)
 * Statements zuordnen
 * 
 * Probieren Sie a,b,c,d  mit dem Format %c, %o und  %x  aus.
 * Was stellen Sie fest?
 *
 * Compile mit 'make'
 */

#include <stdio.h>

int main(void) {
    // Deklaration, Definition und Initialisierung
    char a = 97;
//    short b = 85;
//    int c = 110;
//    long d = 94;

//    float e = 99.444;
//    double f = 3234.9234234;

    // Aufgabe
    // eg: printf("Out: %c\n", c);
	printf("================\n");
	printf("var a:\n");
//    printf("double: %g\n", a);
	printf("signed int: %d\n", a);
	printf("signed int: %i\n", a);
//	printf("double: %f\n", a);
//	printf("double: %e\n", a);
	printf("Oct-int: %o\n", a);
	printf("Hex-int: %x\n", a);
	printf("================\n");


    // special trick question:
    printf("address of var a: %p\n", &a);

    return 0;
}
