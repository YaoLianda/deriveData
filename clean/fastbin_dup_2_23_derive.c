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
void *noise_0xc0000f20_1_3 =malloc( 0x10) ;
int *a = malloc( 0x10); 
void *noise_0xc0000f20_1_7 =malloc( 0x10) ;
int *b = malloc( 0x10); 
int *c = malloc( 16);
free(a);
free(b);
free(a);
void *noise_0xc0000f20_1_2 =malloc( 0x10) ;
int *d = malloc( 0x10); 
int *e = malloc( 16);
int *f = malloc( 16); 
//end
assert(d==f);
printf("%s", "exp state arrive!");
}