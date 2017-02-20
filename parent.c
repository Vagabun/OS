#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_BUF 200

int main() {
	int fd;
	char *myfifo = "/tmp/myfifo";
	char buf[MAX_BUF];
    	pid_t pid = fork();
    	int status;
	printf("%d\n", pid);
    	if (pid) {
              printf("parent\n");
              wait(&status);
    	}
    	else {
          	execl("/home/orsay/Desktop/OS/child.out", "child.out", (char*)NULL);
		fd = open(myfifo, O_RDONLY);
		read(fd, buf, MAX_BUF);
		printf("%s\n", buf);
		close(fd);
    	}
    	return 0;
}
