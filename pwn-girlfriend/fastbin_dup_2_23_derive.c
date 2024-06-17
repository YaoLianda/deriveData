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
void *noise_0xc0000f20_1_4 =malloc( 0x18) ;
int *a = malloc( 0x18); 
void *noise_0xc0000f20_1_7 =malloc( 0x18) ;
int *b = malloc( 0x18); 
void *noise_0xc0000f20_1_2 =malloc( 0x18) ;
int *c = malloc( 0x18);
free(a);
free(b);
free(a);
void *noise_0xc0000f20_1_1 =malloc( 0x18) ;
int *d = malloc( 0x18); 
int *e = malloc( 24);
int *f = malloc( 24); 
//end
assert(d==f);
printf("%s", "exp state arrive!");
}