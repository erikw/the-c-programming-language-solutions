#include <stdio.h>
#include <stdbool.h>
void fetchChar(int *prevChar, int *curChar);

/* The input C code will be printed out with out any comments. */
// "ap\"bd"
/* strange *\/ comment *//* apa */
int main(void)
{
	int curChar = '\0';
	int prevChar;

	 fetchChar(&prevChar, &curChar);
	bool printNewLine = true;
	 while (curChar != EOF) {
		if (curChar == '/') {
			printNewLine = true;
			if (prevChar == '\0' || prevChar == '\n') {
				printNewLine = false;
			}
			fetchChar(&prevChar, &curChar);
			if (curChar == '/') {
				while (curChar != EOF && curChar != '\n') {
					 fetchChar(&prevChar, &curChar);
				}
				if (printNewLine && curChar == '\n') putchar('\n');
			} else if (curChar == '*') {
					fetchChar(&prevChar, &curChar); // Don't match /*/
				do {
					fetchChar(&prevChar, &curChar);
				} while (curChar != EOF && !(prevChar == '*' && curChar == '/'));
				if (printNewLine && curChar == '\n') putchar('\n');
			} else {
				putchar(prevChar);
				if (curChar != EOF) putchar(curChar);
			}
		} else if (prevChar != '\\' && curChar == '"') {
			do {
				putchar(curChar);
				fetchChar(&prevChar, &curChar);
			} while (curChar != EOF && !(prevChar != '\\' && curChar == '"'));
			if (curChar != EOF) {
				putchar(curChar);
			}

		} else {
			if (curChar == '\n') {
				if (printNewLine) putchar('\n');
			} else {
				putchar(curChar);
			}
			printNewLine = true;
		}

		if (curChar != EOF) {
			fetchChar(&prevChar, &curChar);
		}
	 }
	return 0;
}

void fetchChar(int *prevChar, int *curChar)
{
	*prevChar = *curChar;
	*curChar = getchar();	
}
