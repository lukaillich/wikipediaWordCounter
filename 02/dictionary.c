#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 200

void toLower(char *str) {
	for(int i = 0; str[i]; i++) {
		str[i] = tolower(str[i]);
	}
	return;
}

void clearString(char *str) {
	for(int i = 0; str[i]; i++) {
		if (((int)str[i] > 32 && (int)str[i] < 48) || ((int)str[i] > 57 && (int)str[i] < 65) || ((int)str[i] > 90 && (int)str[i] < 97) || ((int)str[i] > 122 && (int)str[i] < 127)) {
			str[i] = ' ';
		} 
	}
	return;
}

int main() {
	FILE *text = fopen("TEXT_final.txt", "r");
	FILE *output = fopen("lista_rijeci.txt", "w");
	char buffer[SIZE];

	if (text == NULL) {
		printf("Error! Could not open file\n"); 
		exit(-1);
	}

	while (fscanf(text, "%s", buffer) != EOF) {
		toLower(buffer);
		clearString(buffer);
		
		char *token = strtok(buffer, " ");
		while(token != NULL) {
			fprintf(output, "%s\n", token);
			token = strtok(NULL, " ");
		}
	}
	fclose(text);
	fclose(output);

	return 0;
}

