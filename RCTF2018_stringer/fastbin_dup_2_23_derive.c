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
int *a = malloc( 120); 
int *b = malloc( 120); 
int *c = malloc( 120);
free(a);
free(b);
free(a);
int *d = malloc( 120); 
int *e = malloc( 120);
int *f = malloc( 120); 
//end
assert(d==f);
printf("%s", "exp state arrive!");
}