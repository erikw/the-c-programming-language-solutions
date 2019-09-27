#include <stdio.h>
/* Escapes backslashes, backspaces and tabulars. */
int main()
{
	int in;
	while ((in = getchar()) != EOF) {
		if (in == '\t') {
			putchar('\\');
			putchar('t');
		} else if (in == '\b') {
			putchar('\\');
			putchar('b');
		} else if (in == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(in);
		}
	}
	return 0;
}
