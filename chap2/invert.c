#include <stdio.h>
unsigned int invert(unsigned x, int p, int n);
int main(void)
{

	printf("invert(0b00000001, 1, 2,) = %#o\n", invert(0b00000001, 1, 2));
	return 0;
}

unsigned int invert(unsigned x, int p, int n)
{
	return (x & (~0  << (p + 1) | ~(~0 << (p + 1- n)))) | (~(~0 << (p + 1)) & ~x);
}
