#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *strcat(char *strDestination, const char *strSource);//strcat 函数声明原型
char* my_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ptr = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++);
	*dest = *src;
	return ptr;
}
int main()
{
	char s1[] = "abcdef";
	char s2[] = "bcd";
	printf("%s\n",my_strcat(s1, s2));
	system("pause");
	return 0;
}