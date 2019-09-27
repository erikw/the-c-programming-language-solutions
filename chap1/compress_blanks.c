#include <stdio.h>
int main(void)
{
	#define SPACE 1 	/* A space character */
	#define NON_SPACE 0	/* A non space character */

	int prev_char = -1;
	int in;
	while ((in = getchar()) != EOF) {
		if (in == ' ') {
			if (prev_char != SPACE) {
				putchar(in);
				prev_char = SPACE;
			}
		} else {
			putchar(in);
			prev_char = NON_SPACE;
		}
	}
	return 0;
}
