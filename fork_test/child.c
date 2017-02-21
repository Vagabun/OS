#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
	int fd;
	char * myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	char str[500] = "child.out(2838) bash(2323) gnome-terminal-(1554) upstart(1408) lightdm(1094) lightdm(1) systemd(0)";
	write(fd, str, sizeof(str));
	close(fd);
	unlink(myfifo);

	return 0;
}
