/*comandos para checar:

./copy_file arquivo_origem.txt arquivo_destino.txt
diff arquivo_origem.txt arquivo_destino.txt
comp arquivo_origem.txt arquivo_destino.txt

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("Erro ao abrir o arquivo de origem");
        return 1;
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0700);
    if (fd2 == -1) {
        if (errno == EEXIST) {
            char response;
            printf("O arquivo de destino já existe. Deseja sobrescrevê-lo? (y/n): ");
            scanf(" %c", &response);
            if (response == 'n' || response == 'N') {
                close(fd1);
                return 0;
            }
            // Se o usuário optar por sobrescrever, tentamos abrir novamente o arquivo.
            fd2 = open(argv[2], O_WRONLY | O_TRUNC, 0700);
            if (fd2 == -1) {
                perror("Erro ao abrir o arquivo de destino");
                close(fd1);
                return 1;
            }
        } else {
            perror("Erro ao abrir o arquivo de destino");
            close(fd1);
            return 1;
        }
    }

    char buf[BUFFER_SIZE];
    ssize_t bytes_read;

    while (bytes_read = read(fd1, buf, sizeof(buf)) > 0) {
        write(fd2, buf, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo de origem");
        close(fd1);
        close(fd2);
        return 1;
    }

    close(fd1);
    close(fd2);

    return 0;
}
