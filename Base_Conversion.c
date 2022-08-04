#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Clear_Screen(){
	
	#ifdef _WIN32
	
		system("cls");
	    
	#else
	    
	    system ("clear");
	    
	#endif
	
}

void getString(char str[],int length, char msg[]){
    printf(msg);
    fflush(stdin);
    fgets(str, length, stdin);
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    puts("");
}

int getInt(char msg[]){
    int integer;

    printf(msg);
    fflush(stdin);
    scanf("%d", &integer);

    puts("");

    return integer;
}

int Check_Number(char number[], int base){
    int i;
    
    for(i = 0 ; i < strlen(number) - 1 ; i++){
        if(base > 10){
            if((( (int) number[i] < 48 || (int) number[i] > 57) && ( (int) number[i] < 65 || (int) number[i] > 90)))

                return 1;

            else if (( (int) number[i] >= 65 && (int) number[i] <= 90) && (int) number[i] > (55 + base - 1)) 

                return 1;
            
        }else{

            if(( (int) number[i] < 48) || ( (int) number[i] > 57))

                return 1;
            
            else if(( (int) number[i] > (48 + base - 1)))
                return 1;

        }
        
    }

    return 0;
}

void main (){
    system("color a");

    int op, base, i, aux = 0, check[2];
    char integer[20] = "", decimal[10] = "", temp[10];
    float sum = 0;

    do{
        printf("\t\tMenu\n\t9. Limpar ecra\n\t2. Converter de qualquer base para decimal\n\t1. Converter de decimal para qualquer base\n\t0. Sair\n\tOpcao: ");
        fflush(stdin);
        scanf("%d", &op);

        switch (op){
            case 9:

                Clear_Screen();

                break;
            case 2:

                do{

                    base = getInt("\nBase: ");
                    
                    getString(integer, 20, "\nNumero\nParte inteira: ");

                    getString(decimal, 10, "Parte decimal: ");

                    if(base < 2 || base > 36)
                        printf("Base incorreta, tente novamente.\n");
                    
                    check[0] = Check_Number(integer, base);
                    check[1] = Check_Number(decimal, base);

                    if(check[0] != 0 || check[1] != 0)
                        printf("Numero nao corresponde a base indicada, tente novamente.\n");

                }while((base < 2 || base > 36) || (check[0] != 0 || check[1] != 0));

                sum = 0;
                for(i = 0; i < strlen(integer); i++){

                    if((int) integer[i] >= 48 && (int) integer[i] <= 57){

                        aux = (int) (integer[i] - 48);

                    }else{
                        aux = (int) (integer[i] - 55);
                    }

                    sum += ((float) aux * pow(base, (strlen(integer) - i - 1)));

                }

                for(i = 0; i < strlen(decimal); i++){

                    if((int) decimal[i] >= 48 && (int) decimal[i] <= 57){

                        aux = (int) (decimal[i] - 48);

                    }else{
                        aux = (int) (decimal[i] - 55);
                    }
                    
                    sum += ((float) aux * pow((double) base, (double) -(i + 1)));

                }
                
                
                strcat(integer,",");
                strcat(integer,decimal);
                printf("\n(%s) na base %d = (%f) na base 10\n", integer, base, sum);

                break;
            case 1:

                do{
                    getString(integer, 20, "\nNumero em base 10\nParte inteira: ");

                    getString(decimal, 10, "Parte decimal: ");

                    base = getInt("\nBase desejada: ");

                    if(base < 2 || base > 36)
                        printf("\nBase incorreta, tente novamente.\n");

                    if(base == 10)
                        printf("\nO numero ja esta em base 10, tente novamente.\n");
                    
                    check[0] = Check_Number(integer, 10);
                    check[1] = Check_Number(decimal, 10);

                    if(check[0] != 0 || check[1] != 0)
                        printf("\nNumero nao corresponde a base indicada, tente novamente.\n");

                }while((base < 2 || base > 36) || base == 10 || (check[0] != 0 || check[1] != 0));

                aux = 0;
                for(i = 0; i < strlen(integer); i++){

                    aux += ((int) ((int) integer[i] - 48) * pow((double) 10, (double) (strlen(integer) - i - 1)));

                }

                printf("\n\naux: %d\n\n", aux);

                //here
                for(i = 0; i < strlen(decimal); i++){

                    

                }

                

                strcat(integer,",");
                strcat(integer,decimal);

                printf("\n(%s) na base 10 = () na base %d\n", integer, base);

                break;
            case 0:

                break;
            default:
                printf("\n\tOpcao invalida, tente novamente\n");
                break;
        }

        strcpy(integer, "");
        strcpy(decimal, "");
        puts("");
        
    }while(op != 0);

    puts("Programa encerrado!\n");
    system("pause");
}