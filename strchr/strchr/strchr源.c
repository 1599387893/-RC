#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


//char *strchr(const char *string, int c);//strchr函数声明原型
char* my_strchr(const char* dest, int c)
{
	assert(dest);
	char* ptr = dest;
	while (*ptr++ != c);
	if (*ptr != '\0')
		return --ptr;
	else
		return NULL;
}
int main()
{
	char s1[] = "abcdef";
	char c = 'n';
	printf("%s\n", my_strchr(s1, c));
	system("pause");
	return 0;
}