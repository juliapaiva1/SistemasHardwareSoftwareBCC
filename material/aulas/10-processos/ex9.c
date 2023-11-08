#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int numero;

    printf("Digite um numero:");
    scanf("%d", &numero);

    pid_t pai, filho;
    int wstatus;
    int variavel;


    pai = getpid();

    for (int i = 1; i<=numero; i++){
    filho = fork();
    variavel +=1;
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Eu sou um processo filho, pid=%d, ppid=%d, meu id do programa e %d\n", filho, pai, variavel);
        sleep(5);
        wait(&wstatus);
        exit(0);
    }
    } 

    return 0;
}

