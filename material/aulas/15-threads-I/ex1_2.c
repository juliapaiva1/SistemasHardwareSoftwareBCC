#include <pthread.h>
#include <stdio.h>

void *minha_thread(void *arg) {
    int *i = (int *)arg;
    int result = i[0] * i[1];
    return (void *)result;
}

void *minha_thread2(void *arg) {
    int *i = (int *)arg;
    int result = i[0] * i[1];
    return (void *)result;
}

int main() {
    int n1;
    int n2;

    printf("Escreva dois numeros: ");
    scanf("%d %d", &n1, &n2);

    pthread_t tid;
    pthread_t tid2;

    int error = pthread_create(&tid, NULL, minha_thread, &n1);
    int error2 = pthread_create(&tid2, NULL, minha_thread2, &n2);

    if (error || error2) {
        printf("Erro ao criar threads.\n");
        return 1;
    }

    void *result1;

    pthread_join(tid, &result1);

    int multiplication1 = (int)result1;
    

    printf("Resultado: %d\n", multiplication1);

    return 0;
}
