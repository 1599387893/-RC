#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//int strncmp(const char *string1, const char *string2, size_t count);


int my_strncmp(const char* s1, const char* s2, size_t count)
{
	assert(s1);
	assert(s2);
	while ((count--) && (*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 > *s2)
			return 1;
		if (*s1 < *s2)
			return -1;
		s1++; s2++;
	}
	if (*s1 != '\0')
		return 1;
	if (*s2 != '\0')
		return -1;
	return 0;
}
int main()
{
	char s1[] = "bcd";
	char s2[] = "bcdd";
	printf("%d\n", my_strncmp(s1, s2, 5));
	system("pause");
	return 0;
}