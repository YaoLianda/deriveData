#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct room {
	size_t size ;
	char *comment;
};
struct room *rooms[10];
void menu(){
	puts("--------------------------------");
	puts("          clean room            ");
	puts("--------------------------------");
	puts(" 1. choice a room               ");
	puts(" 2. exit a room                 ");
	puts(" 3. Exit                        ");
	puts("--------------------------------");
	printf("Your choice :");
}

void choice_room(){
	int i ;
	char buf[4];
	size_t size = 0;
	for(i = 0 ; i < 10 ; i++){
		if(!rooms[i]){
			rooms[i] = (struct room *)malloc(sizeof(struct room));
			printf("Size of comment : ");
			read(0,buf,4);
			size = atoi(buf);
			rooms[i]->comment = (char *)malloc(size);
			rooms[i]->size = size ;
			printf("comment of room:");
			read(0,rooms[i]->comment,size);
			puts("SuccessFul");
			break ;
		}
	}
}
void exit_room(){
	int idx ;
	char buf[4];
	printf("Index :");
	read(0,buf,4);
	idx = atoi(buf);
	if(idx < 0 || idx >= 10){
		puts("Out of bound!");
		_exit(0);
	}
	if(rooms[idx]){
		free(rooms[idx]->comment);
		puts("Done !");	
	}else{
		puts("No such room !");
	}

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
				choice_room();
				break ;
			case 2 :
				exit_room();
				break ;
			case 3 :
				exit(0);
				break ;
			default :
				puts("Invalid Choice");
				break;
		}

	}
	return 0 ;
}
