#include <stdio.h>
#define MAX 100 /* Maximum length of a string to consider. */
int reverse(char s[]);
int get_line(char line[]);

/* Reverse a input string, one line at a time. */
int main(void)
{
	int i;
	char line[MAX];			/* Store the current line. */
	for (i = 0; i < MAX; ++i) {
		line[i] = '\0';
	}
	while (get_line(line) > 0) {
		int top;		/* Top of the array. */
		top = reverse(line);
		printf("%s\n", line);
		for (i = 0; i < MAX; ++i) {
			line[i] = '\0';
		}
	}
	return 0;
}

/* Reverse character string s. Returns end position of the string in the character string array. */
int reverse(char s[])
{
	int top;	/* Top of the character string array. */
	int bottom;	/* Bottom of the character string array. */
	bottom = 0;
	top = -1;
	while (s[++top] != '\0' && top < MAX);	/* Fast forward to top of the array. Would be 
	smoother to pass a parameter from get_line. But the specs forbids this. */
	--top;	
	while (top > bottom) {
		char tmp = s[bottom];
		s[bottom] = s[top];
		s[top] = tmp;
		++bottom;
		--top;
	}
	return (bottom == top) ? top * 2 : top * 2 + 1;
}


/* Get a new line stored in line[], returns 0 when EOF reached. */
int get_line(char line[])
{
	int c;	 	/* Current char. */
	int i = 0;	/* Char index. */
	while ((c = getchar()) != EOF && c != '\n' && i < MAX) {
		line[i++] = c;
	}
	return ( c == '\n' && i == 0) ? 1 : i;
}
