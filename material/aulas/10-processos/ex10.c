#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int vetor[10];
    int menores = 0; // Initialize menores
    int numero;

    for (int i = 0; i < 10; i++) {
        vetor[i] = i;
    }

    printf("Digite um numero:");
    scanf("%d", &numero);

    pid_t pai, filho;
    int wstatus;
    int variavel = 0; // Initialize variavel

    pai = getpid();

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        for (int i = 0; i < 10; i++) {
            if (vetor[i] < numero) {
                menores += 1;
            }
        }
        sleep(5);
        printf("A quantidade de processos menores e %d\n", menores); // Include a newline character

        exit(0);
    }

    wait(&wstatus);

    return 0;
}
