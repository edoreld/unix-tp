#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd = 0;
	fd = close(1); // Close standard output
	assert(fd != 0);
	fd = open("toto", O_WRONLY|O_CREAT, 0600);
	assert(fd == 1);
	execl("/bin/ls", "ls", "-l", NULL);
	perror("execv");
	exit(1);
}
