#if 0
#include <stdio.h>

char* getStr(void)
{
	char s[] = "Hello world";
	return s;
}
void Test()
{
	char* s = "11";
	printf("%s/n",s);
}
int main()
{
	char* str = NULL;
	str = getStr();
	Test();
	printf("%s/n", str);
	return 0;
}
#endif