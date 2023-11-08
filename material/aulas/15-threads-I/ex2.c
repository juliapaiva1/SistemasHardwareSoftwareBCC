#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *tarefa_print_i(void *arg) {
    int *i = (int *)arg;
    printf("Valor de i: %d\n", *i);
    pthread_exit(NULL);
}

int main() {
    int *vi = (int *)malloc(4 * sizeof(int));
    pthread_t *tids = (pthread_t *)malloc(4 * sizeof(pthread_t));

    for (int i = 0; i < 4; i++) {
        vi[i] = i;
        pthread_create(&tids[i], NULL, tarefa_print_i, &vi[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }

    free(vi);
    free(tids); // Libera a memória alocada para tids

    return 0;
}