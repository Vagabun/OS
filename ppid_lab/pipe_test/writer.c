#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 200

int main() {
	int fd;
	//char * myfifo = "/tmp/myfifo";
	char* myfifo = "~/Desktop/myfifo";
	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	char str[] = "oh heyy b0ss can i habe a pussy please";
	write(fd, str, sizeof(str));
	close(fd);
	unlink(myfifo);
    	return 0;
}
