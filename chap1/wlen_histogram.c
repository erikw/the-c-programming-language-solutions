#include <stdio.h>
/* Prints out a histogram of the number of characters per word */
int main(void)
{
	#define MAX_WLEN 5 /* Maximum length of chars per word to consider. */
	#define BLANK		1	/* Blank character. */
	#define NONBLANK	0	/* Non blank character. */
	int in, wlen, prev, hist[MAX_WLEN];
	wlen = 0;
	prev = BLANK;
	int i;
	for ( i = 0; i < MAX_WLEN; ++i) {
		hist[i] = 0;
	}

	while ((in = getchar()) != EOF) {
		if (in == ' ' || in == '\t' || in == '\n') {
			int index = (wlen < MAX_WLEN) ? wlen - 1: MAX_WLEN - 1;
			if (prev != BLANK) {
					++hist[index];
			}
			wlen = 0;
			prev = BLANK;
		} else {
			++wlen;
			prev = NONBLANK;
		}
	}

	for (i = 0; i < MAX_WLEN; ++i) {
		printf("%2d\t|", i + 1);
		int j;
		for (j = 0; j < hist[i]; ++j) {
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
