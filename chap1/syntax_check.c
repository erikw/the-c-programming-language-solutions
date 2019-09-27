#include <stdio.h>
#include <string.h>
void fetchChar(int *prevChar, int *curChar);

/* Check the inputs C syntax. */
int main(void)
{
	int curChar = '\0';
	int prevChar;
	char stack[100];
	int stackp = 0;
	char ERROR_MSG[] = "BAD SYNTAX\n";
	fetchChar(&prevChar, &curChar);
	 while (curChar != EOF) {
		if (curChar == '/') {
			fetchChar(&prevChar, &curChar);
			if (curChar == '/') {
				while (curChar != EOF && curChar != '\n') {
					 fetchChar(&prevChar, &curChar);
				}
			} else if (curChar == '*') {
					fetchChar(&prevChar, &curChar); // Don't match /*/
				do {
					fetchChar(&prevChar, &curChar);
				} while (curChar != EOF && !(prevChar == '*' && curChar == '/'));
			} else {
			if (prevChar != '\\' && curChar == '"') {
			do {
				fetchChar(&prevChar, &curChar);
			} while (curChar != EOF && !(prevChar != '\\' && curChar == '"'));
		} else if (curChar == '(' || curChar == '[' || curChar == '{' || curChar == '\'' || curChar == '"') {
			stack[stackp++] = curChar;		
		} else if (curChar == ')') {
			if (stack[--stackp] != '(') {
				printf(ERROR_MSG);
			}
		} else if (curChar == ']') {
			if (stack[--stackp] != '[') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '}') {
			if (stack[--stackp] != '{') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '\'') {
			if (stack[--stackp] != '\'') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '"') {
			if (stack[--stackp] != '"') {
				printf(ERROR_MSG);
			}
		}
}
		} else if (prevChar != '\\' && curChar == '"') {
			do {
				fetchChar(&prevChar, &curChar);
			} while (curChar != EOF && !(prevChar != '\\' && curChar == '"'));
		} else if (curChar == '(' || curChar == '[' || curChar == '{' || curChar == '\'' || curChar == '"') {
			stack[stackp++] = curChar;		
		} else if (curChar == ')') {
			if (stack[--stackp] != '(') {
				printf(ERROR_MSG);
			}
		} else if (curChar == ']') {
			if (stack[--stackp] != '[') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '}') {
			if (stack[--stackp] != '{') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '\'') {
			if (stack[--stackp] != '\'') {
				printf(ERROR_MSG);
			}
		} else if (curChar == '"') {
			if (stack[--stackp] != '"') {
				printf(ERROR_MSG);
			}
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
