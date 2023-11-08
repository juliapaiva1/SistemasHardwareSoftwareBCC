#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main() {
    pid_t filho;
    int status;

    filho = fork();
    if (filho == 0) {
        // Processo filho
        int i = 1/0;  // Gera uma divisão por zero proposital para simular um erro.

        pid_t child_pid = wait(&status);

    if (WIFEXITED(status)) {
        printf("O filho com PID %d terminou normalmente.\n", child_pid);
        printf("Código de saída: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("O filho com PID %d terminou devido a um sinal.\n", child_pid);
        printf("Sinal: %s\n", strsignal(status));
    }

    return 0;
    }

    // Processo pai
    
}
