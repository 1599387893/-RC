#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int strcmp(const char *string1, const char *string2);//¿âº¯ÊýÔ­ÐÍ

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1);
	assert(s2);
	char* e1 = s1;
	char* e2 = s2;
	while ((*e1 == *e2) && (*e1 != '\0') && (*e2 != '\0'))
	{
		e1++;
		e2++;
	}
	if (*e1 > *e2)
		return 1;
	else if (*e1 < *e2)
		return -1;
	if (*e1 == *e2 == '\0')
		return 0;
}
int main()
{
	char s1[] = "bcde";
	char s2[] = "cde";
	printf("%d\n", my_strcmp(s1, s2));
	system("pause");
	return 0;
}