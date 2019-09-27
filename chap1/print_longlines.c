#include <stdio.h>
#define MINLEN 35 	/* Minimum length for lines to be printed. */
#define MAXLEN 100	/* Maximun length of an input line. */

int getline(char s[], int maxlen);

/* Print lines that are longer than MINLEN. */
int main(void)
{
	int len, i;		 /* Current length of line. */
	char line[MAXLEN];	/* Current line. */	

	while ((len = getline(line, MAXLEN)) > 0 ) {
		if (len >= MINLEN) {
			printf("%s\t:>%d\n", line, len);
		}
		for (i = 0; i < MAXLEN; ++i) {
			line[i] = '\0';
		}
	}
	return 0;
}


int getline(char s[], int maxlen)
{
	int c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < maxlen) {
		s[i++] = c;
	}

	if (c == '\n') {
		s[++i] = c;
	}
	return i;
}
