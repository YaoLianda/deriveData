#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct wideNodles {
    char *money;
};
struct  narrowNodels{
    char *money;
};

struct wideNodles wn;
struct narrowNodels nn;
void menu(){
	puts("--------------------------------");
	puts("         noodles                ");
	puts("--------------------------------");
	puts(" 1. eat wide noodles            ");
    puts(" 2. eat naroow noodles          ");
	puts(" 3. calculate money             ");
	puts(" 4. Exit                        ");
	puts("--------------------------------");
	printf("Your choice :");
}

void narrow_noodles(){
	int narrowNodels_size =0x40;
    nn.money = malloc(narrowNodels_size);
}
void wide_noodles(){
    int wideNodels_size =0x400;
    wn.money = malloc(wideNodels_size);
}
void calculate_money(){
    free(nn.money);
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
				wide_noodles();
				break ;
			case 2 :
				narrow_noodles();
				break ;
			case 3 :
				calculate_money();
				break ;
            case 4 :
                exit(0);
			default :
				puts("Invalid Choice");
				break;
		}

	}
	return 0 ;
}
