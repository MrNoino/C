#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int a, i, c;
	printf("Introduza a altura: ");
	scanf("%i",&a);
	
	puts("");
	
	if(a > 0){
		i = a;
		while (i > 0){
			printf("*");
			
			c = 0;
			
			while(c < a){
				if(c == a-1 || c == 0){
					printf(" ");
				}else if(c == a-i){
					printf("*");
				}else{
					printf(" ");
				}
				
				c++;
			}	
			
			puts("*");
			
			i--;
		}
	}else{
		
		printf("Numero invalido\n");
	}

	system("pause");
}
