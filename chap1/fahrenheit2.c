#include <stdio.h>

/* Show degrees in Fahrenheit and Celsius. */
int main()
{
	printf("fahr \t cels \n");
	// Only with C99 mode: cc -std=c99	
	//for (int i = 300; i >= 0; i -= 20) {
	int i;
	for (i = 300; i >= 0; i -= 20) {
		printf("%3d %6.1f\n", i, (5.0/9.0) * (i - 32));
	}
	return 0;
}
