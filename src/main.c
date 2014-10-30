#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char version[7] = "v0.1";

int main(int argc, char **argv) {
	printf("Welcome to Coin Toss %s\n", version);
	if(argc < 2 || argc > 3) {
		printf("Usage: %s [trials]\n", argv[0]);
		return 1;
	}

	int trials = atoi(argv[1]);
	int heads = 0;
	int tails = 0;

	srand(time(NULL));

	for(int i = 0; i < trials; i++) {
		int r = rand() % 100 + 1;
		if(r <= 50) heads++;
		else tails++;
	}

	printf("Done.\n");
	printf("Heads: %i\n", heads);
	printf("Tails: %i\n", tails);
	return 0;
}
