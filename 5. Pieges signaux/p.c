#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

static void hdl(int sig, siginfo_t *siginfo, void *context)
{
        (void)fprintf(stderr, "Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main(int argc, char **argv, char **envp) {
        struct sigaction act, saveOldAct;

        (void)memset(&act, '\0', sizeof(act));
        (void)memset(&saveOldAct, '\0', sizeof(saveOldAct));

        act.sa_sigaction = (void *)(*hdl);
        act.sa_flags = SA_SIGINFO;

        if(sigaction(SIGINT, &act, &saveOldAct) < 0) {
                perror ("Echec de 'sigaction'");
                return(1);
        }
        while(1) 
                sleep(10);

        return(0);
}