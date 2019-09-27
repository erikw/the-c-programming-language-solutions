#include <stdio.h>
#define MAX_BUFFER	1024	/* Maximum numer of characters to consider a line. */
#define LINE_LEN	10	/* Number of columns to consider a visual line. Must be > 1 */
#define	SPACE		' '	/* A space character. */

int get_line(char line[], int maxBuffer);
void split_line(char line[], int lineLen, int start, int bufferEnd);
void print_line(char line[], int start, int end, int hyphen);

/* Fold long lines. */
int main(void)
{
	char line[MAX_BUFFER];
	int len;		/* Total length of the input line. */
	while ((len = get_line(line, MAX_BUFFER)) > 0) {
		split_line(line, LINE_LEN, 0, len);
	}
	return 0;
}

/* split_line: Recursively splits a line define by the parameter stored in line[]. */
void split_line(char line[], int lineLen, int start, int bufferEnd)
{
	if ((bufferEnd - start) <= lineLen) {
		print_line(line, start, bufferEnd, 0);	
		//split_line(line, lineLen, bufferEnd, bufferEnd);
	} else {
		int pos = start + lineLen;
		/* Fast forward to first space character after last non space character, if it exists. */
		while (pos >= start && line[pos] != SPACE && line[pos] != '\n') {
			--pos;
		}
		while (pos >= start + 1 && line[pos - 1] == SPACE) {
			--pos;
		}

		if (pos < start) { 
			print_line(line, start, start + lineLen - 1, 1);
			split_line(line, lineLen, start + lineLen - 1, bufferEnd);
		} else {
			print_line(line, start, pos, 0);
			split_line(line, lineLen, pos + 1, bufferEnd);
		}
	}
}


/* get_line: Read a line into line[] and returns it's length. */
int get_line(char line[], int maxBuffer)
{
	int i = 0;
	int c;
	while (i < maxBuffer  - 1 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

/* print_line: Prints a line define by the parameter, end with a hypen if hyphen is positive. */
void print_line(char line[], int start, int end, int hyphen)
{
	while (start < end) {
		putchar(line[start++]);
	}
	if (hyphen > 0) {
		putchar('-');
	}
	if (line[end - 1] != '\n') {
		putchar('\n');
	}
}

// defect: or not? When a line begins with spaces, those will be shown on a new line each. Looks bad but it preserves all data.
