#include <stdio.h>

struct testStruct {
    char* array;
};

typedef struct testStruct struct_t;


void alterArray (struct_t* strToMod, char* newArray) {
    strToMod -> array = newArray;

}



int main () {


    char oldArray[]="11111111111\n";
    char newArray[]="22222222222222\n";

    struct_t newStruct;

    alterArray(&newStruct, oldArray);

    printf("%s", newStruct.array);

    alterArray(&newStruct, newArray);

    printf("%s", newStruct.array);






    return 0;
}
