#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_BUF 500

int main(int argc, char* argv[]) {
	int fd;
	char* myfifo = "/tmp/newfifo";
	char buf[MAX_BUF];
    	pid_t pid = fork();
    	if (pid == 0) execl("child.out", "child.out", (char*)NULL);
    	else {
		fd = open(myfifo, O_RDONLY);
		read(fd, buf, MAX_BUF);
		printf("%s\n", buf);
		close(fd);
    	}
    	return 0;
}
