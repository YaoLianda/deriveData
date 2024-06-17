#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
//gcc demo.c -o demo -fno-stack-protector -z execstack -no-pie -z norelro
intptr_t* victim_buffer = NULL;
intptr_t* overflow_buffer = NULL;
intptr_t target_buffer[4] = {0}; // 用于攻击的伪造chunk
int custom1=0;
int random1 =0;

void allocate_victim_buffer_chunk() {
	if (random1!=0){
		printf("random mode just use one time\n");
	}
    printf("Enter random send email mode\n");
    victim_buffer = (intptr_t*)malloc(0x410); // 分配victim_buffer chunk
	random1++;
}

void allocate_overflow_buffer() {
	if (custom1!=0){
		printf("custom mode just use one time\n");
	}
    printf("Enter custom send email mode\n");
    overflow_buffer = (intptr_t*)malloc(0x10); // 分配用于溢出的缓冲区
	custom1++;
}

void free_victim_buffer_chunk() {
    if (victim_buffer==NULL){
        printf("Not in random mod\n");
        exit(0);
    } 
    printf("close random send emial mode\n");
    free(victim_buffer); // 释放victim_buffer chunk
    victim_buffer = NULL;
}

void prepare_fake_chunk() {//使用数组的读进行填充0:0 1:0x410+0x10 2:0 3:address
    printf("Enter a profile\n");
    read(0,target_buffer,4*sizeof(intptr_t));
}

void cause_overflow() {//使用read，这里首先输入一个用户可定义的lenght，再通过length对overflow_buffer进行写操作
    if (overflow_buffer==NULL){
        printf("The custom mode is not entered");
        exit(0);
    }
    printf("please input email length: \n");
    char buf1[4];
    read(0,buf1,4);
    int length = atoi(buf1);
    printf("please email content \n");
    read(0,overflow_buffer,length);
}

void trigger_attack() {
    printf("Open send channel\n");
    char *p2 = malloc(0x410); // 尝试分配一个新的chunk，返回的是target_buffer的地址。
}

void set_barrier(){
    printf("send confirm \n");
    malloc(2);
}

void menu(){
	puts("-----------------------------------------");
	puts("               send email                ");	
	puts("-----------------------------------------");
	puts(" 1. Enter custom send email mode         ");
	puts(" 2. Enter random send email mode         ");
	puts(" 3. send confirm                         ");
	puts(" 4. close random send emial mode         ");
    puts(" 5. Enter a profile                      ");
	puts(" 6. custom email conetnt                 ");
	puts(" 7. Open send channel                    ");
	puts(" 8. Exit                                 ");
	puts("-----------------------------------------");
	printf("Your choice :");
};
int main() {
    setbuf(stdout, NULL);
    printf("Welcome to the email tool!\n");
    char buf[4];
	while(1){
        menu();
		read(0,buf,4);
		switch(atoi(buf)){
			case 1 :
				    allocate_overflow_buffer();
				break ;
			case 2 :
				    allocate_victim_buffer_chunk();
				break ;
			case 3 :
                    set_barrier();
				break ;
            case 4 :
				    free_victim_buffer_chunk(); // 此时victim_buffer的size已经被修改
				break ;
            case 5 :
				    prepare_fake_chunk();//fake_chunk的内容，由输入提供，且需要定制size和bk的内容
				break ;
            case 6 :
				     cause_overflow();
				break ;
            case 7 :
				     trigger_attack(); // 利用已修改的chunk
				break ;
			case 8 :
				exit(0);
				break ;
			default :
				puts("Invalid choice");
				break ;

		}
	}
    return 0;
}