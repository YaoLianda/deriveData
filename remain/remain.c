// gcc remain.c -Wl,-z,relro,-z,now -fPIE -pie -o remain
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE	16
#define MEMO_SIZE	0x48

static int menu(void);
static void add(void);
static void edit(void);
static void delete(void);

static int getnline(char *buf, int len);
static int getint(void);

char *memo[10];

__attribute__((constructor))
int init(){
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
	return 0;
}

int main(void){
	printf("Remain");
	for(;;){
		int a = menu();
		switch(a){
			case 1:
				add();
				break;
			case 2:
				edit();
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

static int menu(void){
	printf(	"\nMENU\n"
			"****************\n"
			"1. Add\n"
			"2. Edit\n"
			"3. Delete\n"
			"0. Exit\n"
			"****************\n"
			"> ");

	return getint();
}

static void add(void){
	char *p;

	if(!(p = (char*)malloc(0x48))){
		puts("malloc failed...");
		return;
	}

	printf("Input memo > ");
	read(0, p, 0x48);

	for(int i = 0; i < sizeof(memo)/sizeof(char*); i++)
		if(!memo[i]){
			memo[i] = p;
			return;
		}

	puts("memo is full!");
	free(p);
	exit(0);
}

static void edit(void){
	unsigned id;

	printf("Input id > ");
	id = getint();
	if(!memo[id]){
		puts("Entry does not exist...");
		return;
	}

	printf("Input new memo > ");
	read(0, memo[id], 0x48);
}

static void delete(void){
	unsigned id;

	printf("Input id > ");
	while((id = getint()) >= sizeof(memo)/sizeof(char*))
		printf("Out of range!!\nInput id > ");

	if(!memo[id]){
		puts("Entry does not exist...");
		return;
	}

	free(memo[id]);
}

static int getnline(char *buf, int size){

	if(size < 0)
		return 0;

	read(0, buf, size);
	return 1;
}

static int getint(void){
	char buf[BUF_SIZE] = {0};

	getnline(buf, sizeof(buf));
	return atoi(buf);
}
