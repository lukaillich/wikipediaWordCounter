#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LAST 1000000
#define SIZE 200

int main() {

	FILE *input = fopen("lista_rijeci_final.txt", "r");

	if (input == NULL) {
		printf("Error! Could not open file\n"); 
		exit(-1);
	}
	
	for (int i = 0; i < 90; ++i) {
		char dest[] = "lista";
		char num[8];
		sprintf(num, "%d", i);
		strcat(dest, num);
		strcat(dest, ".txt");
		FILE *output = fopen(dest, "w");
		char buffer[SIZE];

		int j = 0;
		while (fscanf(input, "%s", buffer) != EOF) {
			fprintf(output, "%s\n", buffer);
			j++;
			if (j >= LAST) break;
		}

		fclose(output);
	}

	fclose(input);
	
	return 0;
}