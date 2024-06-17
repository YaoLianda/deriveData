#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>
//gcc tcache_poisoning_demo.c -o tcache_poisoning_demo -fno-stack-protector -z execstack -no-pie -z norelro
size_t global_var;

struct Resource {
    size_t size;
    intptr_t *data;
};

struct Resource resources[5];
int resource_count = 0;

void obtain_resource() {
    if (resource_count >5) {
        puts("Maximum capacity reached. Cannot obtain more resources.");
        return;
    }

    printf("Enter size of the new resource: ");
    char size_buf[4];
    ssize_t size_read = read(0, size_buf, sizeof(size_buf));
    if (size_read <= 0) {
        puts("Failed to read input.");
        return;
    }
    resources[resource_count].size = atoi(size_buf);

    resources[resource_count].data = (intptr_t *)malloc(resources[resource_count].size);
    if (!resources[resource_count].data) {
        puts("Failed to obtain resources. Allocation error.");
        exit(EXIT_FAILURE);
    }

    resource_count++;
    puts("Resource obtained successfully.");
}

void release_resource() {
    int idx;
    printf("Enter index of resource to release: ");
    char idx_buf[4];
    ssize_t idx_read = read(0, idx_buf, sizeof(idx_buf));
    if (idx_read <= 0) {
        puts("Failed to read input.");
        return;
    }
    printf(" idx_buf is%s xxx",idx_buf);

    idx = atoi(idx_buf);

    if (idx < 0 || idx >= resource_count) {
        puts("Invalid index.");
        return;
    }

    free(resources[idx].data);
    // resources[idx].data = NULL; UAF
    puts("Resource released successfully.");
}

void write_resource() {
    int idx;
    printf("Enter index of resource to write: ");
    char buf[4];
    ssize_t idx_read = read(STDIN_FILENO, buf, sizeof(buf));
    if (idx_read <= 0) {
        puts("Failed to read input.");
        return;
    }
    idx = atoi(buf);

    if (idx < 0 || idx >= resource_count || resources[idx].data == NULL) {
        puts("Invalid index or resource not allocated.");
        return;
    }

    printf("Enter 8 bytes to write into the resource: ");
    // if (idx==1){
    //     resources[idx].data[0]=&global_var;
    //     return ;
    // }
    ssize_t bytes_read = read(0, resources[idx].data, 8);
    if (bytes_read != 8) {
        puts("Failed to read input.");
        return;
    }
    puts("Write success");
}

void show_menu() {
    puts("----------------------");
    puts("       Resource Manager    ");
    puts("----------------------");
    puts(" 1. Obtain resources ");
    puts(" 2. Release resources ");
    puts(" 3. Write resources ");
    puts(" 4. Print resource data ");
    puts(" 5. Exit ");
    puts("----------------------");
    printf("Your choice: ");
}

void print_resource_data() {
    int idx;
    printf("Enter index of resource to print data: ");
    char idx_buf[4];
    ssize_t idx_read = read(0, idx_buf, sizeof(idx_buf));
    if (idx_read <= 0) {
        puts("Failed to read input.");
        return;
    }
    idx = atoi(idx_buf);

    if (idx < 0 || idx >= resource_count || resources[idx].data == NULL) {
        puts("Invalid index or resource not allocated.");
        return;
    }

    printf("Data of resource %d: ", idx);
    for (int i = 0; i < 8; i++) {
        printf("%02x ", *((unsigned char *)resources[idx].data + i));
    }
    printf("\n");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char buf[4];
    while (1) {
        show_menu();
        ssize_t read_bytes = read(0, buf, sizeof(buf));
        if (read_bytes <= 0) {
            puts("Failed to read input.");
            continue;
        }
        switch (atoi(buf)) {
            case 1:
                obtain_resource();
                break;
            case 2:
                release_resource();
                break;
            case 3:
                write_resource();
                break;
            case 4:
                print_resource_data();
                break;
            case 5:
                exit(EXIT_SUCCESS);
            default:
                puts("Invalid choice");
                break;
        }
    }
    return 0;
}
