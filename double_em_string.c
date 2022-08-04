//biblioteca padrao
#include <stdio.h>
//biblioteca de manipulação e funções para strings
#include <string.h>
//biblioteca de manipulação e funções para carateres
#include <ctype.h>
//biblioteca necessaria à instrução system("pause"); (pode retirar se nao lhe fizer falta)
#include <stdlib.h>
//biblioteca com funções matematicas
#include <math.h>

//função para ler uma string
void Ler_String(char string[], int tamanho, char mensagem[]){

    //Imprime a mensagem desejada
    printf(mensagem);
    //Limpa o ficheiro stdin (ficheiro de leitura do input) para não causar problemas
    fflush(stdin);
    //Lê uma string até ao tamanho desejado no ficheiro stdin 
    fgets(string, tamanho, stdin);

    //procedimento para retirar a quebra de linha introduzida pelo usuario
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

    //Imprime uma quebra de linha
    puts("");
}

//função para validar se uma string contem apenas numeros
int Valida_Numero(char numero[]){

    //variavel usada nas iterações do ciclo
    int indice;

    //ciclo que começa em zero e vai até ao tamanho da string -1
    for(indice = 0; indice < strlen(numero); indice++){
        //testa se o carater nao é digito
        if(!isdigit(numero[indice]))
            //se nao for digito retorna valor 0 (equivale a falso, que neste caso é 0 = não é numero)
            return 0;
    }

    //retornará 1 (equivalente a true) se não encontrou nenhum carater que não fosse digito
    return 1;
}

//função para converter as Strings num numero do tipo double
double converte_string_double(char inteiro[], char decimal[]){

    //variavel que vamos usar na conversão para double
    double numero = 0.0;
    //variavel usada nas iterações do ciclo
    int indice;

    //ciclo que começa em zero e vai até ao tamanho da string -1
    for(indice = 0; indice < strlen(inteiro); indice++)
        /*Parte Inteira
        incrementamos na variavel double as operações que no caso permitem converter o codigo ascii de um carater no numero pretendido
        Ex: input parte inteira: 123
            49 codigo ascii - 48 = 1
            50 codigo ascii - 48 = 2
            51 codigo ascii - 48 = 3
            1 * 10 expoente 2 = 100
            2 * 10 expoente 1 = 20
            3 * 10 expoente 0 = 3
            100 + 20 + 3 = 123 (converitdo em double através dos castings "(double)" )
            */
        numero += ((double) ( ((int) inteiro[indice] - 48) * pow((double) 10, (double) (strlen(inteiro) - ( indice + 1)))));

    //ciclo que começa em zero e vai até ao tamanho da string -1
    for(indice = 0; indice < strlen(decimal); indice++)
        /*Parte decimal
        incrementamos na variavel double as operações que no caso permitem converter o codigo ascii de um carater no numero pretendido
        Ex: input parte decimal: 123
            49 codigo ascii - 48 = 1
            50 codigo ascii - 48 = 2
            51 codigo ascii - 48 = 3
            1 * 10 expoente -1 = 1/10 = 0.1
            2 * 10 expoente -2 = 2/100 = 0.02
            3 * 10 expoente -3 = 1/1000 = 0.003
            123 (vem do ciclo anterior) + 0.1 + 0.02 + 0.003 = 123.123 (converitdo em double através dos castings "(double)" )
        */
        numero += ((double) ( ((int) decimal[indice] - 48) *  pow((double) 10, (double) -(indice + 1)))) + 0.0f;
    
    //Exemplos anteriores: numero = 123.123000
    return numero;
}

void main (){
    //variavel onde vamos receber o numero convertido
    double numero;
    //variaveis para guardar os inputs: a parte inteira e a decimal do numero
    char parte_inteira[20], parte_decimal[10];

    //chamamos a função para ler a string e guardar na variavel destinada
    Ler_String(parte_inteira, 20, "Parte inteira: ");

    //chamamos a função para ler a string e guardar na variavel destinada
    Ler_String(parte_decimal, 10, "Parte decimal: ");

    //Valida se o input introduzido pelo usuario é apenas numeros
    if(Valida_Numero(parte_inteira) == 1 && Valida_Numero(parte_decimal) == 1){
        //Imprime a mensagem positiva de que é apenas numeros
        printf("\nO usuario introduziu um numero.\n");
    //Em caso de nao ser apenas numeros
    }else{
        //Imprime a mensagem negativa de que nao é apenas numeros
        printf("\nO usuario nao introduziu um numero.\n");

        //imprime uma quebra de linha
        puts("");

        //instrução necessaria para a minha configuração de ide (pode retirar em caso de nao lhe fazer falta)
        system("pause");

        //termina o programa
        exit(0);
    }

    //atribuição do numero convertido  
    numero = converte_string_double(parte_inteira, parte_decimal);

    //Imprime o numero convertido
    printf("\n\nn: %lf", numero);

    //imprime uma quebra de linha
    puts("");

    //instrução necessaria para a minha configuração de ide (pode retirar em caso de nao lhe fazer falta)
    system("pause");
}
