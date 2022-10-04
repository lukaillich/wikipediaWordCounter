#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_EL 10000000
#define NUM_OF_FILES 90
#define SIZE 200

typedef struct identity{
	char word[SIZE];
	int counter;
} identity;

int cmpF(const void *a, const void * b) {
	const identity *ia = a;
    const identity *ib = b;
	return strcmp(ia->word, ib->word);
}

int main() {
	identity *id = malloc(NUM_OF_EL * sizeof(identity));
	char buffer1[SIZE], buffer2[SIZE], buffer3[SIZE], buffer4[SIZE];
	int inscribed = 0, counter = 0, sum = 0;

	for (int i = 0; i < NUM_OF_FILES; ++i) {
		char url[100] = "stats/stat";
		char num[8];

		sprintf(num, "%d", i);
		strcat(url, num);
		strcat(url, ".txt");

		FILE *f = fopen(url, "r");
		while (fscanf(f, "%s %s %s %s\n", buffer1, buffer2, buffer3, buffer4) != EOF) {
			if (!strcmp(buffer1, "STATISTIKA:") || !strcmp(buffer1, "Suma") || !strcmp(buffer1, "rijeci")) continue;
			strcpy(id[inscribed].word, buffer4);
			id[inscribed].counter = atoi(buffer1);
			inscribed++;
		}
		fclose(f);
	}
	qsort(id, inscribed, sizeof(identity), cmpF);

	identity *finalDictionary = malloc((NUM_OF_EL / 10) * sizeof(identity));
	for (int i = 0; i < inscribed; ++i) {
		counter++;
		strcpy(finalDictionary[counter].word, id[i].word);
		finalDictionary[counter].counter = id[i].counter;
		sum += id[i].counter;

		for (int j = i + 1; j < inscribed; ++j) {
			if (!strcmp(finalDictionary[counter].word, id[j].word)) {
				finalDictionary[counter].counter += id[j].counter;
				sum += id[j].counter;
			} else {
				i = j-1;
				break;
			}

		}
	}

	for (int i = 1; i < counter; ++i) { //// na indexu 0 je greskom zapisana neka cudna vrijednost
		double percent = ((double)finalDictionary[i].counter/(double)sum) * 100;
		printf("%s %d %.10lf %%\n", finalDictionary[i].word, finalDictionary[i].counter, percent);
	}
	printf("\nPronađeno %d različitih riječi!\n", counter);
	printf("Ukupan zbroj riječi: %d\n", sum);
		
	free(id);
	free(finalDictionary);
	
	return 0;
}