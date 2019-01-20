#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s1 = "ab";
	char s2 = "cdefgi";
	strcpy(s1, s2);
	printf("%s\n", s1);
	system("pause");
	return 0;
}