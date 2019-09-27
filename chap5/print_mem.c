#include <stdio.h>

int main(void)
{
	/*char *addr = (char *) 1;*/
	char d = 'A';
	char *addr = &d;
	while(1) {
		printf("%c ", *addr);
		addr++;

	}
	return 0;
}
