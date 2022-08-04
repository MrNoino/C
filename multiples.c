#include <stdio.h>

int main(){
	int number, multiple, range, option;
	char anykey;
	
	do{
		printf("\t\tMenu\n\n\t1. Find Multiples\n\t0. Quit\n\n\tOption: ");
		fflush(stdin);
		scanf("%d", &option);
		puts("");
		//system("cls");
		if(option == 1){
			printf("Number to find the multiples: ");
			fflush(stdin);
			scanf("%d", &number);
			
			puts("");
			
			if(number != 0){
				printf("Range to find multiples: ");
				fflush(stdin);
				scanf("%d", &range);
				
				//system("cls");
				puts("\nMultiples:");
				printf("\n| ");
				
				for(multiple = number; multiple <= range; multiple++){
					if(multiple % number == 0){
						printf("%d | ", multiple);
					}
				}
			}else{
				printf("| 0 |");
			}	
			
			printf("\n\nClick any key to go back to Menu...");
			fflush(stdin);
			scanf("%c", &anykey);
			puts("");
			//system("cls");
		}else if(option != 0){
			puts("Invalid option! Please try again.\n");
		}
	}while(option != 0);
	
	puts("Program closed!");
	
	return 0;
	
}
