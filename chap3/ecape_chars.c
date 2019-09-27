#include <stdio.h>
#define MAX_LINE 80 /* Max char length of a line. */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
	char s[MAX_LINE], u[MAX_LINE], t[] = "ab\t\nd\t\tds";
	escape(s, t);
	printf("escape(%s) = %s\n", t, s);
	unescape( u, s);
	printf("unescape(%s) = %s\n", s, u);

	return 0;
}

void escape(char s[], char t[])
{
	int i , j;
	i = j = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			default: s[j] = t[i];
		}
		i++;
		j++;
	}
	s[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i , j;
	i = j = 0;
	char slashSeq = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
			case '\\':
				if (slashSeq) {
					slashSeq = 0;
					i++;
					if (t[i] == 'n') {
						s[j] = '\n';
					} else if (t[i] == 't') {
						s[j] = '\t';
					} else {
						s[j++] = '\\';
						s[j] = t[i];
					}
					i++;
					j++;
				} else {
					slashSeq = 1;
				}
				break;

			default: s[j++] = t[i++];
		}
	}
	s[j] = '\0';
}
