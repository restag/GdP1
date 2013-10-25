/* Drucke Umrechnungstabelle von Fahrenheit nach Celsius */
/* Richtige Berechnung: 5/9.0 rechnet float              */
/* Falsche  Berechnung: 5/9   rechnet int                */

#include <stdio.h>
#define OK 0

int main() {
    int fahrenheitWert;
    fahrenheitWert = 0;

    printf("Grad Fahrenheit\tGrad Celsius\n");
    while (fahrenheitWert <= 300) {
        int celsiusWert;
        /* Achtung: Zahlformat                         */
        /* 5/9 ergibt ganzzahlige Rechnung             */
        /* Alternative: 5 * (fahrenheitWert - 32) / 9; */
        celsiusWert = 5/9.0 * (fahrenheitWert - 32);

        /* Formatierung: %10d druckt rechtsbuendig     */
        printf("%10d\t%7d\n", fahrenheitWert,celsiusWert);
        fahrenheitWert = fahrenheitWert + 20;
    }
    return OK;
}
