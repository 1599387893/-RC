#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//char *strcpy(char *strDestination, const char *strSource);

char* my_strcpy(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ptr = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return ptr;
}
int main()
{
	char s1[] = "abefg";
	char s2[] = "cdefg";
	printf("%s\n", my_strcpy(s1, s2));
	system("pause");
	return 0;
}