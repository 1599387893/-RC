#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//char *strncpy(char *strDest, const char *strSource, size_t count);

char* my_strncpy(char* dest, const char* src, size_t count)
{
	assert(dest);
	assert(src);
	char* ptr = dest;
	while (count-- && *src != '\0')
	{
		*ptr++ = *src++;
	}
	if (*src == '\0')
		*ptr = '\0';
	return dest;
}
int main()
{
	char s1[] = "abcd";
	char s2[] = "efg";
	printf("%s\n", my_strncpy(s1, s2, 2));
	system("pause");
	return 0;
}