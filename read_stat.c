#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Eventually useless function
void move_pointer (FILE *status) {
	int ptr = fgetc(status);
	//Segmentation fault if make it recursive
	while (ptr != '\n') ptr = fgetc(status);
	return;
}
*/

char* make_filename (int id) {
	char* filename = malloc (sizeof(char) * 20);
	sprintf(filename, "/proc/%d/status", id);
	return filename;
}

int main (void) {

	int fd;
	char *myfifo = "/tmp/myfifo";
	char key_1[] = "Name:";
	char key_2[] = "PPid:";
	char buf[50];	
	char tree[500];
	char id[10];
	int ppid;
	int pid = getpid();
	FILE *status;
	status = fopen(make_filename(pid), "r");
	
	//tree of processes is not correct. FIX 	
	while (status != NULL) {
		while (!feof(status)) {
			fscanf(status, "%s", buf);
			if (strcmp(buf, key_1) == 0) {
				fscanf(status, "%s", buf);
				strcat(tree, buf);
			}
			else if (strcmp(buf, key_2) == 0) {
				fscanf(status, "%s", buf);
				sprintf(id, "(%s)", buf);
				strcat(tree, id);
				strcat(tree, " ");
				ppid = atoi(buf);
			}
		}
		fclose(status);
		status = fopen(make_filename(ppid), "r");
		if (status == NULL) break;
	}

	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	write(fd, tree, sizeof(tree));
   	close(fd);
	unlink(myfifo);	
	//printf("%s\n", tree);
	return 0;
}
