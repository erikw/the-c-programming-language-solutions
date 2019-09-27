#include <stdio.h>
/* Count blanks, tabs and newlines */
int main()
{
	int sp, tabs, nl;
	sp = tabs = nl = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			sp++;
		} else if (c == '\t') {
			tabs++;
		} else if (c == '\n') {
			nl++;
		}
	}
	printf("spaces: %d\n", sp);
	printf("tabs: %d\n", tabs);
	printf("newlines: %d\n", nl);
	return 0;
}
