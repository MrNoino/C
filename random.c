#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    int i;
    srand((unsigned)time(NULL));
 
    for(i=1 ; i <= 10 ; i++) 
        printf("Numero %d: %d\n",i, rand() % 10);
 
    puts("");
    
}