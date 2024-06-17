#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>
//gcc fastbin_dup_demo.c -o fastbin_dup_demo -fno-stack-protector -z execstack -no-pie -z norelro
struct telephone {
    size_t size;
    intptr_t *data;
};
struct Note{
    size_t size;
    intptr_t *content;
};

struct telephone telephones[7];
int telephone_count = 0;
struct Note notes[7];
int note_count = 0;

void obtain_telephone() {
    if (telephone_count >7) {
        puts("Maximum capacity reached. Cannot obtain more telephones.");
        exit(-1);
    }
    void *a = malloc(0x200);
    free(a);
    printf("Enter size of the new telephone: ");
    char size_buf[4];
    ssize_t size_read = read(0, size_buf, sizeof(size_buf));
    if (size_read <= 0) {
        puts("Failed to read input.");
        exit(-1);
    }
    telephones[telephone_count].size = atoi(size_buf);

    telephones[telephone_count].data = (intptr_t *)malloc(telephones[telephone_count].size);
    if (!telephones[telephone_count].data) {
        puts("Failed to obtain telephones. Allocation error.");
        exit(EXIT_FAILURE);
    }

    telephone_count++;
    puts("telephone obtained successfully.");
}
void add_note(){
    if (note_count >7) {
        puts("Maximum capacity reached. Cannot add more notes.");
        exit(-1);
    }

    printf("Enter size of the new note: ");
    char size_buf[4];
    ssize_t size_read = read(0, size_buf, sizeof(size_buf));
    if (size_read <= 0) {
        puts("Failed to read input.");
        exit(-1);
    }
    notes[note_count].size = atoi(size_buf);

    notes[note_count].content = (intptr_t *)calloc(1,notes[note_count].size);
    if (!notes[note_count].content) {
        puts("Failed to add note. Allocation error.");
        exit(EXIT_FAILURE);
    }
    note_count++;
    puts("note add successfully.");
}

void release_telephone() {
    int idx;
    printf("Enter index of telephone to release: ");
    char idx_buf[4];
    ssize_t idx_read = read(0, idx_buf, sizeof(idx_buf));
    if (idx_read <= 0) {
        puts("Failed to read input.");
        exit(-1);
    }
    idx = atoi(idx_buf);

    if (idx < 0 || idx >= telephone_count) {
        puts("Invalid index.");
        exit(-1);
    }

    free(telephones[idx].data);
    telephones[idx].data = NULL;
    puts("telephone released successfully.");
}
void delete_note() {
    int idx;
    printf("Enter index of note to delete: ");
    char idx_buf[4];
    ssize_t idx_read = read(0, idx_buf, sizeof(idx_buf));
    if (idx_read <= 0) {
        puts("Failed to read input.");
        exit(-1);
    }
    idx = atoi(idx_buf);
    if (idx < 0 || idx >= note_count) {
        puts("Invalid index.");
        exit(-1);
    }

    free(notes[idx].content);
    // telephones[idx].data = NULL;May be DBF
    puts("note delete successfully.");
}

void show_menu() {
    puts("----------------------");
    puts("       telephone&note Manager    ");
    puts("----------------------");
    puts(" 1. Obtain telephone ");
    puts(" 2. Release telephone ");
    puts(" 3. add note ");
    puts(" 4. delete note");
    puts(" 5. Exit ");
    puts("----------------------");
    printf("Your choice: ");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char buf[4];
    while (1) {
        show_menu();
        ssize_t read_bytes = read(0, buf, sizeof(buf));
        printf("input xx %d",atoi(buf));
        switch (atoi(buf)) {
            case 1:
                obtain_telephone();
                break;
            case 2:
                release_telephone();
                break;
            case 3:
                add_note();
                break;
            case 4:
                delete_note();
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
