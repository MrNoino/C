#include <stdio.h>



void main (){
 
    int n = 73;

    int r = 0;

    while (n != 1){
        r+= n;
        if(n%2 == 0)
            n = n/2;
        else
            n = 1+(3*n);

        printf("%d\n", r);
    }

}