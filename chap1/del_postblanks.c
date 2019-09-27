#include <stdio.h>
#define MAXLEN 100 /* Maximum lenght of a line to consider. */

int getline(char s[], int maxlen);
int get_eol(char s[], int stringpos);
void print2eol(char s[], int eol_pos);

/* Remove trailing blanks and tabs from input lines, also delete entirely blank lines. */
int main(void)
{
	int len; 		/* Lenght of the current line. */
	int eol_pos;		/* Position of what we consider to be the end of the line. */
	char line[MAXLEN];	/* The current line. */

	while ((len = getline(line, MAXLEN)) > 0) {
		eol_pos = get_eol(line, --len);
		print2eol(line, eol_pos);
	}
	return 0;
}


/* getline: Save next line to s[] and returns the number of characters. */
int getline(char s[], int maxlen)
{
	int c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < maxlen) {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	return i;
}

/* get_eol: Get the position of what we here consider to be the end of the line i.e. last non blank or tab in the string. -1 returned if only blanks or tabs. */
int get_eol(char s[], int stringpos)
{
	while (stringpos >= 0 && (s[stringpos] == ' ' || s[stringpos] == '\t' || (s[stringpos] == '\n' && stringpos > 1))) {
		--stringpos;
	}
	return stringpos;
}

/* print2eol: Prints the string to the given position. */
void print2eol(char s[], int eol_pos)
{
	if (eol_pos >= 0) {
		int i, lastchar;
		for (i = 0; i <= eol_pos; ++i) {
			lastchar = s[i];
			putchar(s[i]);
		}
		if (lastchar != '\n') {
			putchar('\n');
		}
	}
}
