#include <stdio.h>
/* Print input word, one per line. */
int main(void) {
	#define BLANK 		1	/* Blank char. */
	#define NONBLANK	0	/* Non-blank char. */
	
	int in, prev;
	prev = NONBLANK;
	while ((in = getchar()) != EOF) {
		if (in == ' ' || in == '\t' || in == '\n') {
			if (prev != BLANK) {
				putchar('\n');
			}
			prev = BLANK;
		} else {
			putchar(in);
			prev = NONBLANK;
		}
	}
	return 0;
}
