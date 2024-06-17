#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t stack_var;
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
intptr_t *tail_tcache_object = malloc(1032);
intptr_t *tcache_object_uaf = malloc(1032);
free(tail_tcache_object);
free(tcache_object_uaf);
read(0,tcache_object_uaf,8);
intptr_t * use_uaf_object = malloc(1032);
intptr_t * use_fake_object = malloc(1032);
//end
return 0;
}