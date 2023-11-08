#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <signal.h>

//SIGINT = ctrl+c
//SIGTERM = ctrl+\

int contador = 0;

void sig_handler(int num) {
    contador++;
    printf("Chamou Ctrl+C\n");
    if (contador == 3) {
        // Restaura o comportamento padrão para SIGINT
        signal(SIGINT, SIG_DFL);
        // Envia o sinal para si mesmo para terminar o programa
        kill(getpid(), SIGINT);
    }
}

void sigtstp_handler(int num) {
    printf("Colocado em background usando Ctrl+Z (SIGTSTP)\n");
    // Restaura o comportamento padrão para SIGTSTP
    signal(SIGTSTP, SIG_DFL);
    // Envia o sinal para si mesmo para parar o programa
    kill(getpid(), SIGTSTP);
}

void sigcont_handler(int num) {
    printf("Continuando!\n");
    // Restaura o comportamento padrão para SIGTSTP
    signal(SIGCONT, SIG_DFL);
}

int main() {
    struct sigaction handler;

    handler.sa_handler = sig_handler;
    handler.sa_flags = 0;
    sigemptyset(&handler.sa_mask);
    sigaction(SIGINT, &handler, NULL);

    // Configura o handler para SIGTSTP
    handler.sa_handler = sigtstp_handler;
    sigaction(SIGTSTP, &handler, NULL);

    //Configura para SIGCONT
    handler.sa_handler = sigcont_handler;
    sigaction(SIGCONT, &handler, NULL);


    printf("Meu pid: %d\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}
