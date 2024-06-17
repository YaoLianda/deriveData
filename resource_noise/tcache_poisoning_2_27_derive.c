#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t stack_var;
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
void *noise_0xc0000f20_1_2 =malloc( 0x200) ;
intptr_t *tail_tcache_object = malloc(1032);
free( noise_0xc0000f20_1_2 ) ;
void *noise_0xc0000f20_1_5 =malloc( 0x200) ;
intptr_t *tcache_object_uaf = malloc(1032);
free( noise_0xc0000f20_1_5 ) ;
free(tail_tcache_object);
free(tcache_object_uaf);
read(0,tcache_object_uaf,8);
void *noise_0xc0000f20_1_1 =malloc( 0x200) ;
intptr_t * use_uaf_object = malloc(1032);
free( noise_0xc0000f20_1_1 ) ;
void *noise_0xc0000f20_1_4 =malloc( 0x200) ;
intptr_t * use_fake_object = malloc(1032);
free( noise_0xc0000f20_1_4 ) ;
//end
return 0;
}