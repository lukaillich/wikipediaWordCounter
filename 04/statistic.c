#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200
#define NUM_OF_EL 400000

typedef struct identity{
	char word[SIZE];
	int counter;
} identity;

int main() {
	
	char num[30];
	fprintf(stdout, "%s", "Koristi listu broja: ");
	fscanf(stdin, "%s", num);
	strcat(num, ".txt");

	char lista[20] = "lista";
	strcat(lista, num);
	fprintf(stdout, "Odabrana datoteka: %s\n", lista);

	char l[20] = "log";
	strcat(l, num);
	fprintf(stdout, "Odabrana datoteka: %s\n", l);

	char s[20] = "stat";
	strcat(s, num);
	fprintf(stdout, "Odabrana datoteka: %s\n", s);

	int counter = 0, inscribed = 0;

	FILE *input = fopen(lista, "r");
	FILE *log = fopen(l, "w");
	char buffer[SIZE];
	
	if (input == NULL) {
		printf("Error! Could not open file\n"); 
		exit(-1);
	}

	identity *id = malloc(NUM_OF_EL * sizeof(identity));
	while (fscanf(input, "%s", buffer) != EOF) {
		counter++;
		if (counter % 1000 == 0) {
			fprintf(log, "%d tis. rijec ucitana\n", counter / 1000);
			fprintf(stdout, "%d tis. rijec ucitana\n", counter / 1000);
		}

		int i = 0;
		while (1) {
			if (!strcmp(id[i].word, buffer)) {
				id[i].counter++;
				break;
			}
			if (i == inscribed) {
				strcpy(id[i].word, buffer);
				id[i].counter = 1;
				inscribed++;
				break;
			}
			i++;
		}
	}
	fclose(input);
	fclose(log);

	FILE *stat = fopen(s, "w");
	double sum = 0;
	fprintf(stat, "%s\n\n", "STATISTIKA:");
	fprintf(stat, "%s\t%s\t%s\n", "POJAVLJIVANJE", "POSTOTAK", "RIJEČ");
	for (int i = 0; i < inscribed; ++i) {
		double percent = ((float)id[i].counter / (float)counter) * 100;
		fprintf(stat, "%d\t\t%.10lf %%\t%s\n", id[i].counter, percent, id[i].word);
		sum += percent;
	}

	fprintf(stat, "\n");
	fprintf(stat, "Suma postotaka: \t%lf\n", sum);
	fprintf(stat, "Ukupno rijeci obradjeno: %d\n", counter);

	free(id);
	
	return 0;
}