#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}

void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);

    // Bloqueia temporariamente o sinal SIGTERM
    sigprocmask(SIG_BLOCK, &mask, NULL);

    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);

    // Desbloqueia o sinal SIGTERM
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    struct sigaction handler_int;
    struct sigaction handler_term;

    handler_int.sa_handler = sigint_handler;
    handler_int.sa_flags = 0;
    sigemptyset(&handler_int.sa_mask);
    sigaction(SIGINT, &handler_int, NULL);

    handler_term.sa_handler = sigterm_handler;
    handler_term.sa_flags = 0;
    sigemptyset(&handler_term.sa_mask);
    sigaction(SIGTERM, &handler_term, NULL);

    printf("Meu pid: %d\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}

