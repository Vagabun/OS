#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Eventually useless function
void move_pointer (FILE *stat) {
	int ptr = fgetc(stat);
	//Segmentation fault if make it recursive
	while (ptr != '\n') ptr = fgetc(stat);
	return;
}
*/

int main () {

	int pid = getpid();
	char filename[50];
	sprintf(filename, "/proc/%d/status", pid);
	FILE *stat;
	stat = fopen(filename, "r");
	char key_1[] = "Name:";
	char key_2[] = "PPid:";
	char buf[50];	
	char ppid[50];

	while (stat != NULL) {
		while (!feof(stat)) {
			fscanf(stat, "%s", buf);
			if (strcmp(buf, key_1) == 0) {
				fscanf(stat, "%s", buf);
				printf("%s\n", buf);
			}
			else if (strcmp(buf, key_2) == 0) {
				fscanf(stat, "%s", buf);
				strcpy(ppid, buf);
				printf("%s\n", buf);
			}
		}
		fclose(stat);

		sprintf(filename, "/proc/%s/status", ppid);
		printf("%s\n", filename);
		stat = fopen(filename, "r");
	}
		

	if (stat == NULL) perror("Error opening file");
	return 0;
}
