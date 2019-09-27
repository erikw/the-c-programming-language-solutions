#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line size. */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest line from input, with overflow detection. */
int main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	if ((max == MAXLINE - 1) && longest[MAXLINE - 1] == '\0' && longest[MAXLINE - 2] != '\n') {
		printf("Overflow\n");
	}

	if (max > 0) {
		printf("%s", longest);
	}


	return 0;
}

/* Read a line into s, return length. */
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* Copy 'from' into 'to'. */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
