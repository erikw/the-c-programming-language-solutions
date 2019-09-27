#include <stdio.h>

/* Show degrees in Fahrenheit and Celsius. */
int main()
{
	float fahr, celsius;
	int lower = 20;
	int upper = 300;
	int step = 20;

	fahr = lower;
	printf("fahr \t cels \n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %9.2f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}
