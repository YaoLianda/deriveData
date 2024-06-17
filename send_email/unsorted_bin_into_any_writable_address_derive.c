#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

intptr_t* victim = NULL;
intptr_t* overflow = NULL;
intptr_t target[4] = {0}; // 用于攻击的伪造chunk

int main() {
    setbuf(stdout, NULL);
setbuf(stdin, NULL);
    
    read(0, target, 32);
    
    overflow = malloc(16);
    victim = malloc(1040);
    malloc(2);
    free(victim);
    
    read(0, overflow, 48);
    
    char *p2 = malloc(1040);
}