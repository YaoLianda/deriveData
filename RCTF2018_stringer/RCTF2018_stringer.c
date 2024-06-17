#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

long long size_link[40] = {0};
long long string_link[40] = {0};
long long int added_times = 0;
long long edit_times[40] = {0};

void safe_input(void *a1, unsigned int a2) {
    read(0, a1, a2);
    *(unsigned char *)((char *)a1 + a2 - 1) = 0;
}

long long get_input() {
    long long result;
    char s[10] = {0};
    safe_input(s, 0x10);
    result = atoll(s);
    if (result >= 0)
        return result;
    else
        return 0;
}

void ready() {
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void menu() {
    puts("1. New string");
    puts("2. Show string");
    puts("3. Edit string");
    puts("4. Delete string");
    puts("5. Exit");
    printf("choice: ");
}

void new_string() {
    unsigned int size;
    unsigned int nmemb;
    void *strings;
    unsigned long long i; 
    if (added_times > 0x20)
        printf("too many string");
    printf("please input string length: ");
    size = get_input();
    nmemb = size;
    if (!size || size > 0x100)
        printf("invalid size");
    strings = malloc(size);
    if (!strings) {
        printf("memory error");
        exit(1);
    }
    printf("please input the string content: ");
    safe_input(strings, nmemb);
    for ( i = 0; i <= 31 && string_link[i]; ++i)
        ;
    if (i > 31)
        printf("too many string");
    string_link[i] = (long long)strings;
    printf("your string: %s\n", (char *)strings);
    ++added_times;
    size_link[i] = nmemb;
}

void edit_string() {
    unsigned int index;
    unsigned int the_byte;
    long long *strings;

    printf("please input the index: ");
    index = get_input();
    if (index > 0x1F) {
        printf("not a validate index");
        exit(1);
    }
    strings = (long long *)string_link[index];
    if (!strings) {
        printf("not a validate index");
        exit(1);
    }
    unsigned int strings_size = size_link[index];
    if (edit_times[index] <= 4) {
        printf("input the byte index: ");
        the_byte = get_input();
        if (the_byte <= strings_size) {
            ++*((unsigned char *)strings + the_byte);
            ++edit_times[index];
        } else {
            puts("nope!");
        }
    } else {
        puts("nope!");
    }
}

void del_string() {
    unsigned int index;
    void *ptr;

    printf("please input the index: ");
    index = get_input();
    if (index > 0x1F)
        printf("not a validate index");
    ptr = (void *)string_link[index];
    if (!ptr)
        printf("not a validate index");
    free(ptr);
}

void print_string() { puts("Nothing :)"); }

int main(int argc, char **argv, char **envp) {
    int choose;
    ready();
    while (1) {
        while (1) {
            menu();
            choose = get_input();
            if (choose != 1)
                break;
            new_string();
        }
        switch (choose) {
        case 2:
            print_string();
            break;
        case 3:
            edit_string();
            break;
        case 4:
            del_string();
            break;
        default:
            if (choose == 5)
                exit(0);
            puts("wrong choice");
            break;
        }
    }
    return 0;
}
