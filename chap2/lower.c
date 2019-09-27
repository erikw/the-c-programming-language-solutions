#include <stdio.h>

void lower(char string[]);

int main(void)
{
	char string[] = "AaBbCcDdddEE";
	lower(string);
	printf("AaBbCcDdddEE, %s\n", string);
	return 0;
}

void lower(char string[])
{
	int i;
	char c;
	for (i = 0; string[i] != '\0'; ++i) {
		c = string[i];
		string[i] = (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
	}
}
