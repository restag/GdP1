#include <stdio.h>

unsigned int fac_R(unsigned int x);

int main(void) {

    unsigned int i = 5;

    printf("%u\n", fac_R(i));

    return 0;
}

unsigned int fac_R(unsigned int x)
{
    if (x == 0) return 1;

    return fac_R(x-1) * x;
}
