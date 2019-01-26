#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strstr(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ptr1 = dest;
	char* ptr2 = NULL;
	while (*ptr1 != *src && *ptr1 != '\0')
	{
		ptr1++;
		ptr2 = ptr1;
	}
	while (*ptr1 == *src)
	{
		ptr1++;
		src++;
	}
	if (*src != '\0')
		return NULL;
	else
		return ptr2;
}
int main()
{

	char s1[] = "abcdefg";
	char s2[] = "mn";
	printf("%s\n", my_strstr(s1, s2));

	system("pause");
	return 0;
}