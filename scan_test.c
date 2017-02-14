#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input;
	input = fopen("text", "r");
	char str[15];
	char str1[15];
	fscanf(input, "%*s %s", str);
        printf("%s\n", str);
}       
