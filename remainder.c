#include <stdio.h>

int main () {

	int dividend, divisor; 
	
	
	printf("Write the dividend: ");
	fflush(stdin);
	scanf("%d", &dividend);
	
	printf("\nWrite the divisor: ");
	fflush(stdin);
	scanf("%d", &divisor);
	
	printf("\n\nThe remainder of %d / %d is: %d", dividend, divisor, dividend % divisor);

}
