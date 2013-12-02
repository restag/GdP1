#include <stdio.h>
#include <string.h>

#define MAX 256

typedef struct Str{
    int len;
    char str[MAX];
} Str;

// prototypen
Str* reverse(Str* t);

int main(void)
{
    Str test = {.len= 0, .str= "asdig asdhaos daosd"};
    test.len = strlen(test.str);

    //printf("%s", (*reverse(&test))->str);
    printf("%s", reverse(&test)->str);

    return 0;
}

Str* reverse(Str* t)
{
    int i;
    int k = t->len-1;
    char tmp;
    for (i = 0;t->str[i] != '\0'; ++i) {
        if (k<=i) break;
        
        tmp = t->str[i];
        t->str[i] = t->str[k];
        t->str[k--] = tmp;
    }

    return t;
}
