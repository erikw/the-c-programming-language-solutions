#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[] = "anjfedsswe jjdy efed";
	char s2_1[] = "svfrf";
	char s2_2[] = "abc";
	char s2_3[] = "olusf d";
	char s2_4[] = "";
	char d[256];
	strcpy(d, s1);
	squeeze(d, s2_1);
	printf("s1=[%s], s2=[%s], squeeze(s1,s2)=[%s]\n", s1, s2_1, d);

	strcpy(d, s1);
	squeeze(d, s2_2);
	printf("s1=[%s], s2=[%s], squeeze(s1,s2)=[%s]\n", s1, s2_2, d);

	strcpy(d, s1);
	squeeze(d, s2_3);
	printf("s1=[%s], s2=[%s], squeeze(s1,s2)=[%s]\n", s1, s2_3, d);

	strcpy(d, s1);
	squeeze(d, s2_3);
	printf("s1=[%s], s2=[%s], squeeze(s1,s2)=[%s]\n", s1, s2_4, d);

	return 0;
}


void squeeze(char s1[], char s2[])
{
	int i, j, z = 0;
	int deleted;
	for (i = 0; s1[i] != '\0';++i) {
		deleted = 0;
		for (j = 0; s2[j] != '\0' && !deleted; ++j) {
			if (s1[i] == s2[j]) {
				deleted = 1;
			}
		}
		if (!deleted) {
			s1[z++] = s1[i];		
		}
	}
	s1[z] = '\0';
}
