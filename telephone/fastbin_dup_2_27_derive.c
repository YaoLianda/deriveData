#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
void *ptrs[7];
//start 
ptrs[0] = malloc(1); 
ptrs[1] = malloc(1); 
ptrs[2] = malloc(1); 
 ptrs[3] = malloc(1);
ptrs[4] = malloc(1); 
 ptrs[5] = malloc(1);
 ptrs[6] = malloc(1);
free(ptrs[0]); 
 free(ptrs[1]);
 free(ptrs[2]);
 free(ptrs[3]);
 free(ptrs[4]);
 free(ptrs[5]);
 free(ptrs[6]);
int *a = calloc(1, 1); 
int *b = calloc(1, 1); 
int *c = calloc(1, 1); 
free(a);
free(b);
free(a);
int *d = calloc(1, 1); 
int *e = calloc(1, 1); 
int *f = calloc(1, 1); 
//end
assert(d == f);
printf("%s", "exp state arrive!");
}