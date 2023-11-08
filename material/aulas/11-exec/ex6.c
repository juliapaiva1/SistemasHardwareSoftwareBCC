#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    if (argc < 2){
        printf("erro: passe somente 1 argumento");
        return 0;
    }

    int n = atol(argv[1]);
    
    if(n%2 == 0){
        printf("Eh par");
        return 0;
    }

    printf("Nao eh par");

    return 0;
}