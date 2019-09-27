#include <stdio.h>
#define	SPACE		' '	/* A space cahracter. */
#define TAB		'\t'	/* A tabular character. */
#define MAX_BUFFER	1024	/* Maximun number of characters to consider. */

int get_line(char line[], int lim);
int computeSpaces(int pos, int tabLen);

/* Replace tabs to the next tab stop with spaces. */
int main(void)
{
	int tabLen = 4; 	/* Length between a tab start and stop. */
	char line[MAX_BUFFER];	/* Array to store the current line. */
	while (get_line(line, MAX_BUFFER) > 0) {
		int i = 0;	/* index in the char buffer. */
		int j = 0;	/*  Length of the line processed so far. */
		while (line[i] != '\0') {
			if (line [i] == TAB) {
				int nbrSpaces = computeSpaces(j, tabLen);
				int k;
				for (k = 0; k < nbrSpaces; ++k) {
					putchar(SPACE);
					++j;
				}
			} else {
				putchar(line[i]);
				++j;
			}
			++i;
		}
	}
	return 0;
}


/* get_line: Read a line into line[] and return its length. */
int get_line(char line[], int lim)
{
	int c; /* Current character. */
	int i; /* Index. */
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;	
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

/* computeSpaces: Compute the numver of spaces to insert. */
int computeSpaces(int pos, int tabLen)
{
	return tabLen - (pos % tabLen);
}
