#include <stdio.h>
#include <stdlib.h>

struct Linked_List
{
    int numero;
    struct Linked_List * next;

};


void main (){
    int contador = 0;

    struct Linked_List * list =  (struct Linked_List*)malloc(sizeof(struct Linked_List)), * first = list;

    while (contador < 10){
        printf("Numero: ");
        fflush(stdin);
        scanf("%d", &list->numero);

        list->next = malloc(sizeof(struct Linked_List));
        list = list->next;
        contador++;
    }

    list->next = NULL;

    list = first;

    while(list->next != NULL){

        printf("%d | ", list->numero);
        list = list->next;

    }
    puts("");
    list = first;
    
    system("pause");
}