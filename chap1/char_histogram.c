#include <stdio.h>
#include <string.h>
#define MAX_CHARS 94 /* Maximum number of chars to consider. Non-printable characters < 0x33 are not considered. */

/* Prints a histogram of the frequencies of different ASCII characters in the input. */
int main(void)
{
	int in, i, max, m, chars[MAX_CHARS];
	max = 0;
	for (i = 0; i < MAX_CHARS; ++i) {
		chars[i] = 0;
	}
	while ((in = getchar()) != EOF) {
		if (in >= '!' && in <= '~') {
			max = (++chars[in - '!'] > max) ? chars[in - '!'] : max;
		}
	}
	char indent[16];
	int nbrDigits = 0;
	int slice = max;
	while (slice > 0) {
		slice = slice / 10;
		indent[nbrDigits++] = ' ';
	}
	indent[nbrDigits] = ' ';
	indent[nbrDigits + 1] = '\0';

	printf("%s", indent);
	printf("^");
	printf("\t\t\t\tHistogram for the frequencies of the (printable) ASCII characters in the input.\n");
	/* Y-axis and inner loop. */
	for (m = max; m > 0 ; --m) {
		printf("%*d | ", nbrDigits,  m);
		for (i = 0; i < MAX_CHARS; ++i) {
			if (chars[i] >= m) {
				printf("+ ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	/* X-axis */
	printf("%s", indent);
	printf("+-");
	for (i = 0; i < MAX_CHARS; ++i) {
		printf("--");
	}
	printf(">\n");
	/* printf("     "); */
	printf("%s  ", indent);
	for (i = 0; i < MAX_CHARS; ++i) {
		printf("%c ", ('!' + i));
	}
	printf("\n");
	return 0;
}
