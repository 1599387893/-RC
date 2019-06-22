#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

size_t strlen(const char *string);
size_t my_strlen1(const char* string)
{
	assert(string);
	size_t count = 0;
	while (*string++)
	{
		count++;
	}
	return count;
}
size_t my_strlen2(const char* string)
{
	assert(string);
	if (*string == '\0')
		return 0;
	return 1 + my_strlen2(string + 1);
}
int main()
{
	char s[] = "abcdefg";
	printf("%d\n", my_strlen2(s));
	system("pause");
	return 0;
}