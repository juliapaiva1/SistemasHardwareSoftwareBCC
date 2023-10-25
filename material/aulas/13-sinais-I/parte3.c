#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("Meu pid: %d\n", getpid());
        while(1);
        
    }

    

    int ws;
    

    sleep(10)
    kill(filho, SIGKILL)
    
    wait(&ws);

    waitpid(WNOHANG);
    
    printf("EXITED %d \n",
    "SIGNALED %d \n",
    "TERMSIG %d \n",
    "Error: %s\n",
    WIFEXITED(ws),
    WIFSIGNALED(ws),
    WTERMSIG(ws),
    strsignal (WTERMSIG(ws)));

    return 0;
}