#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
int *a = malloc( 120); 
free(a);
int *b = malloc( 1001); 
free(a);
int *c = malloc( 1001);
//end
assert(b==c);
printf("%s", "exp state arrive!");
}