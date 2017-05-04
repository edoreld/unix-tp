#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void sig_handler(int signal)
{
  switch (signal) {
    case SIGINT:
    printf("received SIGINT\n");
    break;
    case SIGCHLD:
    printf("received SIGCHLD\n");
    break;
    }
} 

int main(void)
{
        // To deal with all the signals, we just need to add them here following the template
        // of the SIGINT and SIGCHLD ones, and then add what we want to do when we receive the signal
        // in the sig_handler function

       if (signal(SIGINT, sig_handler) == SIG_ERR) {
        perror("signal");
       }
       if (signal(SIGCHLD, sig_handler) == SIG_ERR) {
        perror("signal");
       }

       while(1)
        sleep(10);
}