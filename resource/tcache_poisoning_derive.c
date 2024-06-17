#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t stack_var;
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
    
intptr_t *tail_tcache_object = malloc(2);
intptr_t *tcache_object_uaf = malloc(2);
free(tail_tcache_object);
free(tcache_object_uaf);
//UAF VULN
read(0,tcache_object_uaf,8);
intptr_t * use_uaf_object = malloc(2);
intptr_t * use_fake_object = malloc(2);
return 0;
}