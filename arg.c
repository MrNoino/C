#include <stdio.h>

int main (int argc , char **argv)
{
    printf ("ola, sou o programa --%s --, chamado com %i argumentos ", argv [0], argc);
    puts(argv[1]); // Mostrar argumento 1
    puts(argv[2]); // Mostrar argumento 2
    return 0;
}
