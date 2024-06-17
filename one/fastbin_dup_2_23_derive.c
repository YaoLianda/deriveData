#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
void *ptrs[7];
//start 
int *a = malloc( 64); 
int *b = malloc( 64); 
int *c = malloc( 64);
free(a);
free(b);
free(a);
int *d = malloc( 64); 
int *e = malloc( 64);
int *f = malloc( 64); 
//end
assert(d==f);
printf("%s", "exp state arrive!");
}