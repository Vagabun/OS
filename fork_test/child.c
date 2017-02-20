#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
	int fd;
	char * myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	//WHY after initializing fd parent falls into infinite loop?!
	//char str[] = "oh heyy b0ss can i habe a pussy please";
	//write(fd, str, sizeof(str));
	//close(fd);
	//unlink(myfifo);

	return 0;
}
