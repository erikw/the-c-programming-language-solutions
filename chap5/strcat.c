#include <stdio.h>

void strcat2(char *, char b[]);

 int main(void)
{
	char a[34] = "ThisIsPart A, ";
	char *b= "and this is part B";
	strcat2(a, &b[0]);
	printf("%s\n", a);
	return 0;
}

void strcat2(char *a, char b[])
{
	while (*a)
		++a;
	while ((*a++ = *b++))
		;
}
