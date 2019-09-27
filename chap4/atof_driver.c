#include <stdio.h>
/* Convert ASCII to float number. */

int main(void)
{
	double atof(char s[]);

	printf("-123.45, %g\n", atof("-123.45"));
	printf("-123.45e-2, %g\n", atof("-123.45e-2"));
	return 0;
}

