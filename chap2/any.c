#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(void)
{
	char s1[] = "anjfedsswe jjdy efed";
	char s2_1[] = "svfrf";
	char s2_2[] = "abc";
	char s2_3[] = "olusf d";
	char s2_4[] = "";
	char d[256];
	strcpy(d, s1);
	printf("s1=[%s], s2=[%s], any(s1,s2)=[%d]\n", s1, s2_1, any(d, s2_1));

	strcpy(d, s1);
	printf("s1=[%s], s2=[%s], any(s1,s2)=[%d]\n", s1, s2_2, any(d, s2_2));

	strcpy(d, s1);
	printf("s1=[%s], s2=[%s], any(s1,s2)=[%d]\n", s1, s2_3, any(d, s2_3));

	strcpy(d, s1);
	printf("s1=[%s], s2=[%s], any(s1,s2)=[%d]\n", s1, s2_4, any(d, s2_4));

	return 0;
}


int any(char s1[], char s2[])
{
	int i, j;
	int found = 0;
	for (i = 0; s1[i] != '\0' && !found;++i) {
		found = 0;
		for (j = 0; s2[j] != '\0' && !found; ++j) {
			if (s1[i] == s2[j]) {
				found = i;
			}
		}
	}
	return found;
}
