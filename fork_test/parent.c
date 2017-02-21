#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_BUF 200

int main(int argc, char* argv[]) {
	int fd;
	char * myfifo = "/tmp/myfifo";
	char buf[MAX_BUF];
	pid_t pid = fork();
	int status;
	if (pid == 0) execl("child", "child", (char*)NULL);
	else {
		fd = open(myfifo, O_RDONLY);
	read(fd, buf, MAX_BUF);
	printf("Received: %s\n", buf);
	close(fd);
	}
	/*if (pid) {
		printf("parent\n");
		//wait(&status);
	}
	else {
		execl("child", "child", (char*)NULL);
	}*/
	
	return 0;
}
