#include <stdio.h>
#include <limits.h>

/* Print data type ranges by headers and computations. */

int main(void)
{
	printf("From limits.h:\n");
	printf("Type\t\t[min, max]\n");
	printf("char\t\t[%d, %d]\n", CHAR_MIN, CHAR_MAX);
	printf("signed char\t[%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char\t[%d, %d]\n", 0, UCHAR_MAX);
	printf("int\t\t[%d, %d]\n", INT_MIN, INT_MAX);
	printf("short\t\t[%d, %d]\n", SHRT_MIN, SHRT_MAX);
	printf("long\t\t[%ld, %ld]\n", LONG_MIN, LONG_MAX);

	printf("From computations.h:\n");

	char c, cmax, cmin =0;
	c = cmax = cmin = 0;
	while (++c > cmax) cmax = c;
	c = 0;
	while (--c < cmin) cmin = c;
	printf("char\t\t[%d, %d]\n", cmin, cmax);


	signed char sc, scmax, scmin;
	sc = scmax = scmin = 0;
	while (++sc > scmax) scmax = sc;
	sc = 0;
	while (--sc < scmin) scmin = sc;
	printf("signed char\t[%d, %d]\n", scmin, scmax);


	unsigned  char uc, ucmax, ucmin;
	uc = ucmax = ucmin = 0;
	while (++uc > ucmax) ucmax = uc;
	uc = 0;
	while (--uc < ucmin) ucmin = uc;
	printf("unsigned char\t[%d, %d]\n", ucmin, ucmax);


	int i, imax, imin;
	i = imax = imin = 0;
	while (++i > imax) imax = i;
	i = 0;
	while (--i < imin) imin = i;
	printf("int\t\t[%d, %d]\n", imin, imax);


	short int si, simax, simin;
	si = simax = simin = 0;
	while (++si > simax) simax = si;
	si = 0;
	while (--si < simin) simin = si;
	printf("short\t\t[%d, %d]\n", simin, simax);

	long int li, limax, limin;
	li = limax = limin = 0;
	while (++li > limax) limax = li;
	li = 0;
	while (--li < limin) limin = li;
	printf("long\t\t[%ld, %ld]\n", limin, limax);

	return 0;
}
