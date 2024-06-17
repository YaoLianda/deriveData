#include <stdio.h>
#include <stdlib.h>
int main(){
	void *ptr=malloc(0x20);
	void *ptr2=malloc(0x20);
	free(ptr);
	free(ptr2);
	free(ptr);
	return 0;
		
}
