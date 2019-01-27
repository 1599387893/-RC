#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//char *strncat(char *strDest, const char *strSource, size_t count);

char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest);
	assert(src);
	char* ptr = dest;
	while (*ptr++ != '\0');
	ptr--;
	while (count-- && *src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return dest;
		
}
int main()
{
	char s1[] = "abcd";
	char s2[] = "efgh";
	printf("%s\n", my_strncat(s1, s2, 5));
	system("pause");
	return 0;
}