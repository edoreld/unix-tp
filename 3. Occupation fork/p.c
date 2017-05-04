#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
	pid_t pid, exit_status;
	struct rlimit rl;

	getrlimit(RLIMIT_NPROC,&rl);

	printf("\n Default value is: %lld\n", (long long int) rl.rlim_cur);

	rl.rlim_cur = 0;

	setrlimit(RLIMIT_NPROC,&rl);

	getrlimit(RLIMIT_NPROC,&rl);

	printf("\n Current value is: %lld\n", (long long int) rl.rlim_cur);

	while(1) {
		exit_status = fork();
		if ((exit_status == 0)) {
			printf("Child reporting and exiting");
			return 0;
		} else if (exit_status == -1) {
			printf("Fork failed");
			return -1;
		} else {
			printf("Parent reporting and exiting");
			return 0;
		}

	}
}
