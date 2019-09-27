#include <stdio.h>
#define MAX_BUFFER	1024	/* Maximum buffer for a line. */
#define	TAB		'\t'	/* A tab character- */
#define	SPACE		' '	/* A space character. */

int get_line(char line[], int lim);

/* Replace a sequence of space characters with tabs and or spaces. */
int main(void)
{
	int tabSize = 8;
	char line[MAX_BUFFER];
	int len;		/* Length of current input line. */
	while ((len = get_line(line, MAX_BUFFER)) > 0) {
		int i;		/* Buffer index. */
		int j = 0;	/* Index in the output line. */
		for (i = 0; i <= len; ++i) {
			int spaces = 0;
			while (line[i] == SPACE && i < len) {
				++spaces;
				++j;
				++i;
			}
			if (spaces > 0) {
				int addTabs = spaces / tabSize;
				int addSpaces = spaces - addTabs * tabSize;
				//int addSpaces = spaces % tabSize;
				int l; 
				for (l = 0; l < addTabs; ++l) {
					putchar(TAB);
					++j;
				}
				for (l = 0; l < addSpaces; ++l) {
					putchar(SPACE);
					++j;
				}
			}
			putchar(line[i]);
			++j;
						
		}
	}

	return 0;
}

/* get_line: Reads a line to line[] and returns its length. */
int get_line(char line[], int lim)
{

	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

