#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void)
{
	printf("setbits(0b0000001, 2, 3, 0b01010010) = %#o\n", setbits(0b00000001, 2, 3, 0b01010010));
	return 0;
}

int setbits(int x, int p, int n, int y)
{
	if ((n - p) <= 0 || (n - p) > (8 * sizeof(int))) {
		return x;
	} else {
	int zeroPattern = 0;
	int i;
	for (i = 0; i < n; ++i) {
		zeroPattern <<= 1;
		zeroPattern |= 0b1;
	}
	int yBits = y & zeroPattern;
	if (p > 0) {
		zeroPattern <<= p - 1;
		yBits <<= p - 1;
	}
	zeroPattern = ~zeroPattern;
	x &= zeroPattern;
	return x |= yBits;
	}
}
