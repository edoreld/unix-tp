#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (){
        int t, pid, etat;
        printf("Processus de depart\n");
        if((t = fork()) == -1) {
                perror("Fork");
                return 1;
        } else if(t == 0) {
                printf("Enfant: attendre 5 secondes\n");
                sleep(5);
                printf("Enfant: Fin\n");
                return 0;
        } else {
                for(;;) {
                        pid = wait(&etat);
                        if(pid == t)
                                break;
                        printf("Parent: 'wait' a rendu la valeur %d\n", pid);
                        if(pid == -1)
                                perror("Wait");
                }
                printf("Parent: status de l'enfant %d\n", etat);
                printf("Parent: Fin d'execution\n");
                return 0;
        }
}
