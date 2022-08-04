#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    char str[1000], op;

    do{
        puts("");
        system("cls");
        printf("Digite a string (Max: 1000): ");
        fflush(stdin);
        fgets(str, 1000, stdin);

        printf("\nTamanho da string: %d\n", strlen(str));
        system("pause");
        system("cls");

        printf("(N)ovamente\n(S)air\nOpcao: ");
        fflush(stdin);
        op = getchar();
        
    }while(op != 's' && op != 'S');

    system("cls");
    system("pause");
}