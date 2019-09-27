#include <stdio.h>

int main(void)
{
	printf("sizeof()\tbits\n");
	printf("char\t\t%4d\n", 8 * sizeof(char));
	printf("short int\t%4d\n", 8 * sizeof(short int));
	printf("int\t\t%4d\n", 8 * sizeof(int));
	printf("long int\t%4d\n", 8 * sizeof(long int));
	printf("float\t\t%4d\n", 8 * sizeof(float));
	printf("double\t\t%4d\n", 8 * sizeof(double));

	return 0;
}
