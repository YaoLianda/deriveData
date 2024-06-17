#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ANIMALS 40

char nameofzoo[16];

typedef struct Animal {
    char name[24];
    int weight;
    void (*speak)(struct Animal*);
    void (*info)(struct Animal*);
} Animal;

typedef struct Dog {
    Animal base;
} Dog;

typedef struct Cat {
    Animal base;
} Cat;

Animal* animallist[MAX_ANIMALS];
int animal_count = 0;

void dog_speak(Animal* a) {
    printf("Wow ~ Wow ~ Wow ~\n");
}

void dog_info(Animal* a) {
    printf("|---------------------|\n");
    printf("| Animal info         |\n");
    printf("|---------------------|\n");
    printf("  Weight: %d\n", a->weight);
    printf("  Name: %s\n", a->name);
    printf("|---------------------|\n");
}

void cat_speak(Animal* a) {
    printf("Meow ~ Meow ~ Meow ~\n");
}

void cat_info(Animal* a) {
    printf("|---------------------|\n");
    printf("| Animal info         |\n");
    printf("|---------------------|\n");
    printf("  Weight: %d\n", a->weight);
    printf("  Name: %s\n", a->name);
    printf("|---------------------|\n");
}

void menu() {
    printf("*********************************\n");
    printf(" 1. Add a dog                    \n");
    printf(" 2. Add a cat                    \n");
    printf(" 3. Listen a animal              \n");
    printf(" 4. Show a animal info           \n");
    printf(" 5. Remove a animal              \n");
    printf(" 6. Exit                         \n");
    printf("*********************************\n");
}

void get_input(char* buffer, size_t size) {
    read(STDIN_FILENO, buffer, size) ;
}

int get_int_input() {
    char buffer[16];
    get_input(buffer, sizeof(buffer));
    return atoi(buffer);
}

void add_dog() {
    char name[16];
    int weight;
    printf("Name: ");
    get_input(name, sizeof(name));
    printf("Weight: ");
    weight = get_int_input();
    Dog* mydog = (Dog*)malloc(sizeof(Dog));
    if (mydog == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(mydog->base.name, name);
    mydog->base.weight = weight;
    mydog->base.speak = dog_speak;
    mydog->base.info = dog_info;
    animallist[animal_count++] = (Animal*)mydog;
}

void add_cat() {
    char name[16];
    int weight;
    printf("Name: ");
    get_input(name, sizeof(name));
    printf("Weight: ");
    weight = get_int_input();
    Cat* mycat = (Cat*)malloc(sizeof(Cat));
    if (mycat == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(mycat->base.name, name);
    mycat->base.weight = weight;
    mycat->base.speak = cat_speak;
    mycat->base.info = cat_info;
    animallist[animal_count++] = (Animal*)mycat;
}

void remove_animal() {
    if (animal_count == 0) {
        printf("no any animal!\n");
        return;
    }
    printf("index of animal: ");
    int idx = get_int_input();
    if (idx < 0 || idx >= animal_count) {
        printf("out of bound!\n");
        return;
    }
    free(animallist[idx]);
    for (int i = idx; i < animal_count - 1; i++) {
        animallist[i] = animallist[i + 1];
    }
    animal_count--;
}

void show_info() {
    if (animal_count == 0) {
        printf("no any animal!\n");
        return;
    }
    printf("index of animal: ");
    int idx = get_int_input();
    if (idx < 0 || idx >= animal_count) {
        printf("out of bound!\n");
        return;
    }
    animallist[idx]->info(animallist[idx]);
}

void listen_animal() {
    if (animal_count == 0) {
        printf("no any animal!\n");
        return;
    }
    printf("index of animal: ");
    int idx = get_int_input();
    if (idx < 0 || idx >= animal_count) {
        printf("out of bound!\n");
        return;
    }
    animallist[idx]->speak(animallist[idx]);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    printf("Name of Your zoo: ");
    get_input(nameofzoo, sizeof(nameofzoo));
    while (1) {
        menu();
        printf("Your choice: ");
        int choice = get_int_input();
        printf("\n");
        switch (choice) {
            case 1:
                add_dog();
                break;
            case 2:
                add_cat();
                break;
            case 3:
                listen_animal();
                break;
            case 4:
                show_info();
                break;
            case 5:
                remove_animal();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
