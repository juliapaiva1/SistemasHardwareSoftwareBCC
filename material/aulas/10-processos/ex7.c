#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    int n2;
    int wstatus;

    float numero;
    printf("Digite dois numeros:");
    scanf("%d", &n1);
    scanf("%d", &n2);

    pid_t pai, filho;

    int multiplica = n1*n2;
    float divide = n1/n2;
    int soma = n1+n2;
    int subtracao = n1-n2;

    pai = getpid();

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Multiplicado: %d\n", multiplica);
        sleep(5);
        wait(&wstatus);
        exit(0);
        
    } 

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Divide: %f\n", divide);
        sleep(5);    
        wait(&wstatus);
        exit(0);
    
    } 

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Subtrai: %d\n", subtracao);
        sleep(5);    
        wait(&wstatus);
        exit(0);
    
    } 

    filho = fork();
    if (filho == 0) {
        pai = getppid();
        filho = getpid();
        printf("Soma: %d\n", soma);
        sleep(5);    
        wait(&wstatus);
        exit(0);
    
    } 
    exit(0);

    return 0;
}

