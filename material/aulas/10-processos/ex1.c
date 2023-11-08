#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pai, filho;
    int variavel = 0;
    int wstatus;


    pai = getpid();
        printf("Eu sou o processo pai, pid=%d, meu id do programa e %d\n", 
            pai, variavel);

    for (int i = 1; i<9; i++){
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

    while (wait(NULL) > 0);

    return 0;
}

