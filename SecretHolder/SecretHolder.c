#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
char *s_ptr;
char *f_ptr;
char *q_ptr;
int s_flag;
int f_flag;
int q_flag;

void add()
{
    char buf[4];
    char *ptr;
    unsigned int choice;
    puts("Which level of secret do you want to keep?");
    puts("1. Small secret");
    puts("2. Big secret");
    puts("3. Huge secret");
    memset(buf, 0 ,sizeof(buf));
    read(0, buf, sizeof(buf));
    choice = atoi(buf);

    switch(choice)
    {
        case 1:
            if(f_flag)
                return;
            f_ptr = malloc(40);
            f_flag = 1;
            puts("Tell me your secret: ");
            read(0, f_ptr, 40);
            break;
        case 2:
            if(s_flag)
                return;
            s_ptr = malloc(40*100);
            s_flag = 1;
            puts("Tell me your secret: ");
            read(0, s_ptr, 40*100);
            break;
        case 3:
            if(q_flag)
                return;
            q_ptr = malloc(40*100);
            q_flag = 1;
            puts("Tell me your secret: ");
            read(0, q_ptr, 40*100);
            break;
    }

}

void del()
{
    char buf[4];
    int choice;
    puts("Which Secret do you want to wipe?");
    puts("1. Small secret");
    puts("2. Big secret");
    puts("3. Huge secret");
    memset(buf, 0, sizeof(buf));
    read(0, buf, sizeof(buf));
    choice = atoi(buf);

    switch(choice)
    {
        case 1:
            free(f_ptr);
            f_flag = 0;
            break;
        case 2:
            free(s_ptr);
            s_flag = 0;
            break;
        case 3:
            free(q_ptr);
            q_flag = 0;
            break;
    }

}

void update()
{
    char buf[4];
    int choice;
    puts("Which Secret do you want to renew?");
    puts("1. Small secret");
    puts("2. Big secret");
    puts("3. Huge secret");
    memset(buf, 0, sizeof(buf));
    read(0, buf, sizeof(buf));
    choice = atoi(buf);

    switch(choice)
    {
        case 1:
            if(f_flag)
            {
                puts("Tell me your secret: ");
                read(0, f_ptr, 40);
            }
            break;
        case 2:
            if(s_flag)
            {
                puts("Tell me your secret: ");
                read(0, s_ptr, 40*100);
            }
            break;
        case 3:
            if(q_flag)
            {
                puts("Tell me your secret: ");
                read(0, q_ptr, 40*100);
            }
            break;
    }
    
}

void handler(){
    puts("Timeout!");
    exit(1);
}

void init_prog(){

    setvbuf(stdout, 0,2,0);
}


int main()
{
    char buf[4];
    unsigned int choice;
    init_prog();
    puts("Hey! Do you have any secret?");
    puts("I can help you to hold your secrets, and no one will be able to see it :)");
    while(1){
        puts("1. Keep secret");
        puts("2. Wipe secret");
        puts("3. Renew secret");

        memset(buf, 0 ,sizeof(buf));
        read(0, buf, sizeof(buf));
        choice = atoi(buf);
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                update();
                break;
        }
    }

}
