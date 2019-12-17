#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"
#include<assert.h>
#include<iostream>
#include<string.h>

using namespace std;
int my_strlen(char* str)
{
#if 0
	assert(str);
	int ret = 0;
	while (*str++ != '\0')
		ret++;
	return ret;
#endif 
#if 0
	assert(str);
	char* p = str;
	while (*p!= '\0')
		p++;
	return p - str;
#endif 
	assert(str);
	if (*str == '\0')
		return 0;
	return 1 + my_strlen(str+1);
}
char* my_strcpy(char* dest, const char* src)
{
	assert(src!=NULL);
	assert(dest != NULL);
	char* str = dest;
	while (*dest++ = *src++);
	return str;
}
char* my_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ptr = dest;
	while (*dest != '\0')
		dest++;
	while (*dest++ = *src++);
	*dest = *src;
	return ptr;
}
char* my_strstr(char* str1, const char* str2)
{

}
//int my_strcmp(const char* src, const char* dest);
//void* my_memcpy(void* dest, const void* src, size_t count);
//void* my_memmove(void* dest, const void* src, size_t count);

int main()
{
	char s[] = "abcdedfg";
	char s1[] = "abc";
	cout << "s.size() = " << my_strlen(s)<<endl;
	//cout << "s1 = " << my_strcpy(s1, s) << endl;
	cout << "s1+s2 = " << my_strcat(s1,s)<<endl;
	system("pause");
	return 0;
}