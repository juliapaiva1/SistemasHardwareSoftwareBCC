#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {

    int wstatus;
    pid_t p1, p2, p3, p4, p5;

    p1 = getpid();
    printf("Meu pid e %d\n", p1);

    p2 = fork();
    if (p2 == 0) {
        p1 = getppid();
        p2 = getpid();
        printf("Meu pid e %d e o pid do processo que me criou e %d\n", p2, p1);
        sleep(5);
        wait(&wstatus);
            exit(0);

    }

    p3 = fork();
    if (p3 == 0) {
        p1 = getppid();
        p3 = getpid();
        printf("Meu pid e %d e o pid do processo que me criou e %d\n", p3, p1);
        sleep(5);
        wait(&wstatus);
            exit(0);

    }

    p3 = getpid();

    p4 = fork();
    if (p4 == 0) {
        p3 = getppid();
        p4 = getpid();
        printf("Meu pid e %d e o pid do processo que me criou e %d\n", p4, p3);
        sleep(5);
        wait(&wstatus);
            exit(0);

    }

    p5 = fork();
    if (p5 == 0) {
        p3 = getppid();
        p5 = getpid();
        printf("Meu pid e %d e o pid do processo que me criou e %d\n", p5, p3);
        sleep(5);
        wait(&wstatus);
        exit(0);

    }
    exit(0);
    
    return 0;
    } 

    


