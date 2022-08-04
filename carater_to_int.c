#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main (){
    char c;
    int i;

    printf("Carater: ");
    fflush(stdin);
    c = getchar();

    if (isdigit(c)){

        i = (int) (c - 48);
        printf("\n\nConvertido para inteiro: %d\n", i);

    }else{

        printf("\n\nCarater nao e numero\n");

    }
        

    


    puts("");
    system("pause");
}