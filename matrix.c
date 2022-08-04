#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main(){
    system("color a");

    int i, random;
    srand( (unsigned)time(NULL) );
    
    while(1==1){
        for(i=0; i < 212 ; i++){

            do

                random = rand() % 127;

            while(random < 32);
            
            printf("%c ", random);
        }
        usleep(50000);  
    }
    
 
    puts("");
}