#include<stdio.h>

#define MAX_Z 3
#define MAX_S 4
#define SUCCESS 0
#define FAILURE 1

// Array mit explizit spezifizierten Grenzen fuer alle Dimensionen
// und expliziten Grenzen fuer Iteration.
// Erste Dimension kann angegeben werden, wird aber ignoriert.
// Alle weiteren Dimensionen muessen angegeben werden!
void drucke1(int feld[MAX_Z][MAX_S], int zAnz, int sAnz) {
  int i,j;

  for(i = 0; i < zAnz; i++) {
    for (j = 0; j < sAnz; j++) {
      printf("%d ",feld[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return;
}

// Offenes Array
// Angabe von zweiter Diemension MAX_S ist Pflicht!
void drucke2(int feld[][MAX_S], int zAnz, int sAnz) {
  int i,j;

  for(i = 0; i < zAnz; i++) {
    for (j = 0; j < sAnz; j++) {
      printf("%d ",feld[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return;
}

/* Die folgende Variante ist falsch.
   Man muss die Anzahl der Spalten angeben!
   Nur die erste Dimension eines mehrdimensionalen
   Arrays darf weggelassen werden

   void drucke3(int feld[MAX_Z][], int zAnz, int sAnz) {
   ...
   }
   */

int main(void) {
  int a[MAX_Z][MAX_S] = {
    {1,2,3,2},
    {4,2,3,2},
    {1,2,3,2}
  };

  drucke1(a,MAX_Z,MAX_S);
  drucke2(a,MAX_Z,MAX_S);

  return SUCCESS;
}
