#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ground {
	size_t size ;
	char *content ;
};
struct ground *groundarray[10];

void buy_ground(){
	int i ;
	char buf[8];
	size_t size = 0;
	for(i = 0 ; i < 10 ; i++){
		if(!groundarray[i]){
			struct ground local;
			groundarray[i] = &local;
			if(!groundarray[i]){
				puts("Allocate Error");
				exit(1);
			}
			printf("Size of ground : ");
			read(0,buf,8);
			size = atoi(buf);
			groundarray[i]->content = (char *)malloc(size);
			if(!groundarray[i]->content){
				puts("Allocate Error");
				exit(2);
			}
			groundarray[i]->size = size ;
			printf("Content of ground :");
			read(0,groundarray[i]->content,size);
			puts("SuccessFul");
			break ;
		}
	}
}

void sale_gorund(){
	int idx ;
	char buf[4];
	printf("Index :");
	read(0,buf,4);
	idx = atoi(buf);
	if(idx < 0 || idx >= 10){
		puts("Out of bound!");
		_exit(0);
	}
	if(groundarray[idx]){
		free(groundarray[idx]->content);
		groundarray[idx]->content = NULL ;
		puts("Done !");	
	}else{
		puts("No such ground !");
	}

}
void repair_ground(){
	int idx ;
	char buf[4];
	printf("Index :");
	read(0,buf,4);
	idx = atoi(buf);
	if(idx < 0 || idx >= 10){
		puts("Out of bound!");
		_exit(0);
	}
	if(groundarray[idx]){
		printf("Content of ground : ");
		read(0,groundarray[idx]->content,groundarray[idx]->size+1);
		puts("Done !");
	}else{
		puts("No such ground !");
	}
}

void menu(){
	puts("--------------------------------");
	puts("          ground deal           ");
	puts("--------------------------------");
	puts(" 1. buy a ground                ");
	puts(" 2. sale a ground               ");
	puts(" 3. repair_ground               ");
	puts(" 4. exit                        ");
	puts("--------------------------------");
	printf("Your choice :");
}

int main(){
	char buf[4];
	setvbuf(stdout,0,2,0);
	setvbuf(stdin,0,2,0);
	while(1){
		menu();
		read(0,buf,4);
		switch(atoi(buf)){
			case 1 :
				buy_ground();
				break ;
			case 2 :
				sale_gorund();
				break ;
			case 3 :
				repair_ground();
				break;
			case 4 :
				exit(0);
				break ;
			default :
				puts("Invalid Choice");
				break;
		}

	}
	return 0 ;
}
