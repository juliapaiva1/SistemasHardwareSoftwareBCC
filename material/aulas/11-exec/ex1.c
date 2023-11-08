#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    if (argc < 3){
        printf("erro: passe no minimo 2 argumentos");
        return 0;
    }

    int soma;

    int v1 = atoi(argv[1]);
    int v2 = atoi(argv[2]);

    soma = v1 + v2;

    printf("soma: %d", soma);

    return 0;
}