#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//gcc test.c -o test -fno-stack-protector -z execstack -no-pie -z norelro

int main()
{
	setbuf(stdout, NULL);
	void *ptrs[7];
	for (int i=0; i<7; i++) {
		ptrs[i] = malloc(0x78);
	}
	for (int i=0; i<7; i++) {
		free(ptrs[i]);
	}
	int *a = calloc(1, 0x78);
	int *b = calloc(1, 0x78);
	int *c = calloc(1, 0x78);
	free(a);
	// printf("If we free %p again, things will crash because %p is at the top of the free list.\n", a, a);
	// free(a);
	// printf("So, instead, we'll free %p.\n", b);
	free(b);
	free(a);
	a = calloc(1, 0x78);
	b = calloc(1, 0x78);
	c = calloc(1, 0x78);
}
