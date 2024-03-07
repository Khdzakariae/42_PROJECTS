#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    static int tmp1 = 0;
    static char tmp = 0;
    tmp = tmp << 1 | (sig == SIGUSR1);
    tmp1++;
    if (tmp1 == 8) {
        write(1, &tmp, 1);
        tmp1 = 0;
        tmp = 0;
    }
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    printf("Le PID du serveur est %d\n", getpid());
    while (1) {
    }
    return 0;
}
