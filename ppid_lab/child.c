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
	char* myfifo = "/tmp/newfifo";
	char key_1[] = "Name:";
	char key_2[] = "PPid:";
	char buf[100];	
	char buf1[20];
	char tree[100];
	char id[10];
	int ppid;
	int pid = getpid();
	FILE* status;
	status = fopen(make_filename(pid), "r");
	strcpy(tree, "->");
	while (status != NULL) {
		while (fgets(buf, sizeof buf, status) != NULL) {
			sscanf(buf, "%s", buf1);
			if (strcmp(buf1, key_1) == 0) {
				sscanf(buf, "%*s %s", buf1);
				strcat(tree, buf1);
			}
			else if (strcmp(buf1, key_2) == 0) {
				sscanf(buf, "%*s %s", buf1);
				sprintf(id, "(%d)", pid);
				strcat(tree, id);
				strcat(tree, " ");
				pid = atoi(buf1);
				ppid = atoi(buf1);
			}
		}
		if (feof(status)) fclose(status);
		status = fopen(make_filename(ppid), "r");
	}	
			
	//printf("%s\n", tree);
	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	write(fd, tree, sizeof(tree));
   	close(fd);
	unlink(myfifo);	

	return 0;
}
