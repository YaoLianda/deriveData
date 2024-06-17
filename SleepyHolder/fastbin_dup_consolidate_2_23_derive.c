#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
int *a = malloc( 40); 
free(a);
int *b = malloc( 4000); 
free(a);
int *c = malloc( 4000);
//end
assert(b==c);
printf("%s", "exp state arrive!");
}