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
void *noise_0xc0000f20_1_8 =malloc( 0x28) ;
int *a = malloc( 120); 
void *noise_0xc0000f20_1_7 =malloc( 0x28) ;
int *b = malloc( 120); 
void *noise_0xc0000f20_1_1 =malloc( 0x28) ;
int *c = malloc( 120);
free(a);
free(b);
free(a);
void *noise_0xc0000f20_1_2 =malloc( 0x28) ;
int *d = malloc( 120); 
void *noise_0xc0000f20_1_5 =malloc( 0x28) ;
int *e = malloc( 120);
void *noise_0xc0000f20_1_6 =malloc( 0x28) ;
int *f = malloc( 120); 
//end
assert(d==f);
printf("%s","exp state arrive!");
}