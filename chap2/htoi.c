#include <stdio.h>

unsigned int htoi(char hex[]);

 int main(void)
{
	printf("htoi(0x0) = %d, expt = %d\n", htoi("0x0"), 0);
	printf("htoi(0x1) = %d, expt = %d\n", htoi("0x1"), 1);
	printf("htoi(0X8) = %d, expt = %d\n", htoi("0X8"), 8);
	printf("htoi(0XA) = %d, expt = %d\n", htoi("0XA"), 10);
	printf("htoi(0Xa) = %d, expt = %d\n", htoi("0Xa"), 10);
	printf("htoi(0xF) = %d, expt = %d\n", htoi("0xF"), 15);
	printf("htoi(0xFA) = %d, expt = %d\n", htoi("0xFA"), 250);
	printf("htoi(0xF3) = %d, expt = %d\n", htoi("0xF3"), 243);
	printf("htoi(0x13) = %d, expt = %d\n", htoi("0x13"), 19);
	printf("htoi(0x03) = %d, expt = %d\n", htoi("0x03"), 3);
	printf("htoi(0x0b) = %d, expt = %d\n", htoi("0x0b"), 11);
	printf("htoi(0b) = %d, expt = %d\n", htoi("0x0b"), 11);
	printf("htoi(0x23v3) = %d, expt = %d\n", htoi("0x23v3"), 0);

	return 0;
}

unsigned int htoi(char hex[])
{
	unsigned int res = 0;
	int c, part;
	int valid = 1;
	int i = -1;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
		i = 1;
	}
	while (hex[++i] != '\0' && valid) {
		res *= 16;
		c = hex[i];
		if (c >= '0' && c <= '9') {
			part = c - '0';
		} else if (c >= 'a' && c <= 'f') {
			part =  10 + c - 'a';
		} else if (c >= 'A' && c <= 'F') {
			part =  10 + c - 'A';
		} else {
			valid = 0;
		}
		res += part;
	}

	return valid ? res : 0;
}
