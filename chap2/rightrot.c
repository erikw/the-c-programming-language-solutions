#include <stdio.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, int n);
int main(void)
{
	printf("rightrot(0b00000111, 3) = %#o\n", rightrot(0b00000111, 3));
	return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	unsigned int b;
	for (; n >=0; --n) {
		b = ((0b1 & x) << (CHAR_BIT * sizeof(int) - 1)) | (~0 >> 1);
		x >>= 1;
		x |= b;
	}
	return x;
}
