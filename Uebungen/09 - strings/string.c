#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct String {
    int length;
    char* msg;
};

typedef struct String string_t;

string_t createString(char* msgContent){

    int strLength = strlen(msgContent);

    string_t tmp;

    tmp.length = strLength;
    tmp.msg = strdup(msgContent);

    return tmp;

}

int main () {

    char msg1[] = "das Ist der erste";
    char msg2[] = "das der 2., aber länger";

    string_t mystring1 = createString(msg1);
    printf("1. String: %s, Länge: %2d\n", mystring1.msg, mystring1.length);


    return 0;
}
