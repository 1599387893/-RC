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
	assert(str1);
	assert(str2);
	char* ret = NULL;
	while (*str1 != '\0')
	{
		ret = str1;
		while (*ret == *str2)
		{
			ret++;
			str2++;
		}
		if (*str2 == '\0')
			break;
		str1++;
	}
	return str1;
}
int my_strcmp(const char* src, const char* dest)
{
	assert(src);
	assert(dest);
	while (*src == *dest)
	{
		src++;
		dest++;
	}
	if (*src > *dest)
		return 1;
	else if (*src == *dest)
		return 0;
	return -1;
}
void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	char* d = (char*)dest;
	char* s = (char*)src;
	while (count--)
	{
		*d = *s;
		d++;
		s++;
	}
	return dest;
}
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	//（1）当源内存的首地址等于目标内存的首地址时，不进行任何拷贝
	//（2）当源内存的首地址大于目标内存的首地址时，实行正向拷贝
	//（3）当源内存的首地址小于目标内存的首地址时，实行反向拷贝
	char* _dest = (char*)dest;
	char* _src = (char*)src;
	if ( _dest > _src) // 从高地址到低地址拷贝
	{
		while (count--)
		{
			*(_dest + count) = *(_src + count);
		}
	}
	else //从低地址到高地址拷贝
	{
		while (count--)
		{
			*_dest = *_src;
			_dest++;
			_src++;
		}
	}
	return dest;
}

int main()
{
	char s[] = "abcdedfg";
	char s1[] = "cde";
	cout << "s.size() = " << my_strlen(s)<<endl;
	//cout << "s1 = " << my_strcpy(s1, s) << endl;
	//cout << "s1+s2 = " << my_strcat(s1,s)<<endl;
	//cout << "strstr= " << my_strstr(s,s1)<<endl;
	//int i = my_strcmp(s, s1);
	//cout << "strcmp = " << i  << end;
	//printf("%d\n",my_strcmp(s,s1));
	//cout << "memcpy() = " << (char*)(my_memcpy(s+1,s1,2))<<endl;
	cout << "memmove() = " << (char*)(my_memmove(s + 2, s, 12)) << endl;
	//cout << "memmove() = " << (char*)(memmove(s + 2, s, 12)) << endl;
	system("pause");
	return 0;
}