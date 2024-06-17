// gcc one.c -Wl,-z,relro,-z,now -fPIE -pie -o one
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE	128
#define MEMO_SIZE	64

static void menu(void);
static void add(void);
static void show(void);
static void delete(void);

static int getnline(char *buf, int len);
static int getint(void);

char *memo;

__attribute__((constructor))
int init(){
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
	return 0;
}

int main(void){
	printf("just one");
	char buf[BUF_SIZE];
	for(;;){
		menu();
		fgets(buf, BUF_SIZE, stdin);
		int index = atoi(buf);
		
		switch(index){
			case 1:
				add();
				break;
			case 2:
				show();
				break;
			case 3:
				delete();
				break;
			case 0:
				goto end;
			default:
				puts("Wrong input.");
				continue;
		}
		puts("Done.");
	}

end:
	puts("Bye!");

	return 0;
}

static void menu(void){
	printf(	"\nMENU\n"
			"================\n"
			"1. Add\n"
			"2. Show\n"
			"3. Delete\n"
			"0. Exit\n"
			"================\n"
			"> ");
}

static void add(void){
	if(!(memo = (char*)malloc(MEMO_SIZE))){
		puts("malloc failed...");
		return;
	}
	printf("Input memo > ");
	fgets(memo,MEMO_SIZE,stdin);
}

static void show(void){
	if(!memo){
		puts("Entry does not exist...");
		return;
	}
	puts(memo);
}

static void delete(void){
	if(!memo){
		puts("Entry does not exist...");
		return;
	}

	free(memo);
}


