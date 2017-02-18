#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *input;
	input = fopen("text", "r");
	char key_1[] = "Name:";
	char key_2[] = "PPid:";
	char str[15];
	char str1[15];
	fscanf(input, "%s %s", str, str1);
	fscanf(input, "%s %s", str, str1);
	//printf("%s - %s", str, str1);
	if (strcmp(str, key_2) == 0) printf("%s\n", str1);
	else printf("wrong\n");
	return 0;
}       
