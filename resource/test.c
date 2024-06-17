#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
size_t stack_var;
int main()
{
	// disable buffering
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	intptr_t *a = malloc(1032);
	intptr_t *b = malloc(1032);
	free(a);
	free(b);
	b[0] = (intptr_t)&stack_var;
    malloc(1032);
	intptr_t *c = malloc(1032);
	return 0;
}

