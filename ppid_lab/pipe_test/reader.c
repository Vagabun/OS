#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_BUF 200

int main() {
	int fd;
	//char * myfifo = "/tmp/myfifo";
	char* myfifo = "~/Desktop/myfifo";
	char buf[MAX_BUF];
	fd = open(myfifo, O_RDONLY);
	read(fd, buf, MAX_BUF);
	printf("Received: %s\n", buf);
	close(fd);
    	return 0;
}
