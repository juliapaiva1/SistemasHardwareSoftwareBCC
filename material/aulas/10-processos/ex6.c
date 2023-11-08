#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    float numero;
    int wstatus;
    printf("Digite um numero:");
    scanf("%f", &numero);

    pid_t pai, filho;
    int variavel = 0;

    int dobro = numero*2;
    float metade = numero/2;

    pai = getpid();

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Dobro: %d\n", dobro);
        sleep(5);
        wait(&wstatus);
        exit(0);
        
    } 

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Metade: %f\n", metade);
        sleep(5);
        wait(&wstatus);
        exit(0);    
    
    } 

    return 0;
}

