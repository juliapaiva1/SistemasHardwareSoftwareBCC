#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int eh_par(int num) {
    if (num % 2 == 0) {
        return 1;  // Retorna 1 se o número é par
    } else {
        return 0;  // Retorna 0 se o número é ímpar
    }
}

int main() {
    int num;

    while (1) {
        printf("Digite um número (-1 para sair): ");
        scanf("%d", &num);

        if (num == -1) {
            break;  // Encerra o loop se -1 for digitado
        }

        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("Fork failed");
            return 1;
        }

        if (child_pid == 0) {  // Processo filho
            int result = eh_par(num);
            exit(result);
        } else {  // Processo pai
            int status;
            wait(&status);

            if (WIFEXITED(status)) {
                int child_exit_status = WEXITSTATUS(status);
                if (child_exit_status == -1) {
                    break;  // Encerra o loop se o filho retornar -1
                } else if (child_exit_status == 1) {
                    printf("O número %d é par.\n", num);
                } else {
                    printf("O número %d é ímpar.\n", num);
                }
            }
        }
    }

    return 0;
}
