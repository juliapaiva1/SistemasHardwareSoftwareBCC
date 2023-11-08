#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int num) {
    printf("Interrompi o sleep!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tempo>\n", argv[0]);
        return 1;
    }

    int tempo = atoi(argv[1]);

    struct sigaction st;
    st.sa_handler = handler;
    st.sa_flags = SA_RESTART;
    sigemptyset(&st.sa_mask);
    sigaction(SIGTERM, &st, NULL);

    printf("PID do processo: %d\n", getpid());
    while (tempo > 0) {
        printf("Tempo restante: %d\n", tempo);
        tempo = sleep(tempo);
    }

    printf("Tempo restante: 0\n");
    printf("Terminou!\n");

    return 0;
}
