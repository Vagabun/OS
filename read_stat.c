#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Eventually useless function
void move_pointer (FILE *stat) {
	int ptr = fgetc(stat);
	//Segmentation fault if make it recursive
	while (ptr != '\n') ptr = fgetc(stat);
	return;
}
*/

int main () {

	FILE *stat;
	stat = fopen("status", "r");
	char key_1[] = "Name:";
	char key_2[] = "PPid:";
	char buf[50];	
	if (stat == NULL) perror("Error opening file");
	else 
	{
		while (!feof(stat)) {
			fscanf(stat, "%s", buf);
			if (strcmp(buf, key_1) == 0) {
				fscanf(stat, "%s", buf);
				printf("%s\n", buf);
			}
			else if (strcmp(buf, key_2) == 0) {
				fscanf(stat, "%s", buf);
				printf("%s\n", buf);
			}
		}
		fclose(stat);
	}
	return 0;
}
