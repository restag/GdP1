/* 
 * Snippet: readALine.c ( aka "FeedMe" )
 * Shows how to read input into a buffer
 * avoiding BufferOverflow.
 * As extra i is equal to strlen(buffer)
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>


#define BUF_SIZE 16

int main(void) {
    char buf[BUF_SIZE];
    int c, i = 0;
    
    puts("\n\t\"WELCOME TO FEED ME!\"\n");

    puts("\n>> Can I haz input?");

    /* Interesting part */
    while((buf[i++] = c = getchar()) != EOF && c != '\n' && i < BUF_SIZE)
        ;
    buf[--i] = '\0';
    // proves that strlen(buf) == i:
    assert(strlen(buf) == i);              

    /* Silly part */
    printf(">> \"%s\" -- omnomnom ", buf);
    printf("%d tasty inputs! ^^\n", i);
    int inputsLeft = BUF_SIZE - i;
    if (inputsLeft > 1) {
        printf(">> But my tummy is not full! You could've give me %d more delicious inputs!\n", inputsLeft);
        puts(">> I'M GOING TO STARVE!\n>> =(\n");
        puts("\n\t*The program dies from starvation. Shame on you!*\n");
    }
    else {
        puts(">> \"YUMMY YUMMY I GOT STUFF IN MY TUMMY!!\"\n>> I'm full! thx! =)\n");
        puts("\n\t*The program happily rubs its belly... a happy ending*\n");
    }


    return 0;
}
