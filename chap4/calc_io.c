#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

/* getch: get a (possible pushed back) character */
int getch(void)
{
	if (bufp > 0)
		return buf[--bufp];
	else {
		if (buf[0] == EOF)
			return EOF;
		else {
			int c = getchar();
			if (c == EOF)
				buf[0] = c;
			return c;
		}
	}
		
	return (bufp > 0) ? buf[--bufp] : getchar();	
}

/* ungetch: push character back to input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else  {
		if (c == EOF)
			printf("error: can't unget EOF\n");
		else
			buf[bufp++] = c;
	}
}

/* ungets: push a string back to input */
void ungets(int s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	for (; i >=0; --i) 
		ungetch(s[i]);
}

void printInSeq(void)
{
	printf("> ");
}
